#include "constants.hpp"
#include "functions.hpp"
#include "GameManager.hpp"
#include "Framework.hpp"
#include "ResourceManager.hpp"

GameManager::GameManager(int NumberKIs)
    :AnzahlKIs(NumberKIs)
{
    upMainMenuButton = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(25,25),sf::Vector2f(200,50),"Main Menu")));

    AnzahlStartkarten = 10;

    font = std::move(std::shared_ptr<sf::Font>(new sf::Font));

    font->loadFromFile("Resources\\PAPYRUS.TTF");
    StatusText      = new sf::Text;
    StatusText->setFont(*font);
    StatusText->setCharacterSize(25);
    StatusText->setFillColor(sf::Color::Black);
    StatusText->setPosition(sf::Vector2f(30,250));
    StatusText->setStyle(sf::Text::Bold);

    PlayedText      = new sf::Text;
    PlayedText->setFont(*font);
    PlayedText->setCharacterSize(25);
    PlayedText->setFillColor(sf::Color::Black);
//    PlayedText->setPosition(sf::Vector2f(1350,250));
    PlayedText->setStyle(sf::Text::Bold);

    StatusRect.setFillColor(sf::Color::Cyan);
    StatusRect.setPosition(20,240);

    sortiert        = new card[AnzahlKIs+1];
    isPlayerTurn    = true;
    isKITurn        = true;

    pGameDeck       = ResourceManager::getNewDeckPTR();
    pSpiel1         = new Reihen;
    pSpieler1       = new Spieler("Niklas",1);
    pKI             = new KI_Spieler[AnzahlKIs];

    SpielerWantPlay = new card;
    SpielerPlay     = new card;
    KIPlay          = new card[AnzahlKIs];

     //// Animations ////
    upAnimatedCards = move(std::unique_ptr<animations> (new animations));
    ////////////////////

    // Initialize deck and shuffle
    for(int i = 0;i<AnzahlKIs;i++){
        pKI[i].setnr(i);
        pKI[i].setSpielerNr(i+2);
    }

    // Karten an Spieler, KI und Reihen austeilen
    card *ForRows;
    ForRows = new card[4];
    for(int i = 0;i<AnzahlStartkarten;i++){
        pSpieler1->giveCard(pGameDeck->austeilen());
        for(int j = 0;j < AnzahlKIs;j++){
            pKI[j].giveCard(pGameDeck->austeilen());
        }
        if(i<4){
            ForRows[i] = pGameDeck->austeilen();
        }
    }

    pSpiel1->setFirst(ForRows);
    delete[] ForRows;
    ForRows = NULL;

    for(int i = 0;i<AnzahlKIs;i++){
        pKI[i].sortCards();
    }
    pSpieler1->sortCards();
    pSpieler1->setTurn();

    //Print Gamestatus to the console
    pSpiel1->printReihen();
    pSpieler1->giveUpdate();

}

GameManager::~GameManager()
{
    delete StatusText;
    delete PlayedText;
    delete[] sortiert;
    delete pSpiel1;
    delete pSpieler1;
    delete SpielerWantPlay;
    delete SpielerPlay;
    delete[] KIPlay;
    delete[] pKI;
}

void GameManager::update(Framework &frmwrk)
{
    upMainMenuButton->update();

    // KI Spielen lassen und Karten anlegen, wenn der Spieler NICHT am Zug ist, danach ist der Spieler wieder am Zug.
    if(!pSpieler1->getPlayerTurn())
    {
        if(isKITurn){
            KITurn();
            EvaluatePlayed();
        }

        if(upAnimatedCards->AnimationFinished()){
            pSpieler1->setTurn();
            isKITurn = true;
            pSpiel1->printReihen();
            pSpieler1->giveUpdate();
        }
    }

    pSpieler1->update();
    pSpiel1->update();

    this->ShowHornochsenStatus();
}

void GameManager::handle(Framework &frmwrk)//handle(sf::Event *event)
{
    upMainMenuButton->handle(frmwrk.pMainEvent);
    if(frmwrk.pMainEvent->type == sf::Event::MouseButtonPressed && frmwrk.pMainEvent->mouseButton.button == sf::Mouse::Left){
        if(upMainMenuButton->getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::MAINMENU);
        } else if(pSpieler1->getPlayerTurn()){
            // Nach zu spielenden Karten fragen
            SpielerWantPlay = pSpieler1->askCard(frmwrk.pMainEvent);
            if(!pSpieler1->getPlayerTurn()){
                *SpielerPlay = *SpielerWantPlay;
            }
        }
    }

    pSpieler1->handle(frmwrk.pMainEvent);
    pSpiel1->handle(frmwrk.pMainEvent);
}

void GameManager::render(Framework &frmwrk)
{
    upMainMenuButton->render(frmwrk.pRenderWindow);

    frmwrk.pRenderWindow->draw(StatusRect);
    frmwrk.pRenderWindow->draw(PlayedRect);

    pSpiel1->render(frmwrk.pRenderWindow);
    pSpieler1->render(frmwrk.pRenderWindow);
    upAnimatedCards->render(frmwrk.pRenderWindow);

    frmwrk.pRenderWindow->draw(*StatusText);
    frmwrk.pRenderWindow->draw(*PlayedText);
}

void GameManager::KITurn(){

    //Maybe don't allocate these on the heap?
    reihenKarten    = new card[4*5];
    Reihenlaenge    = new int[4];

    pSpiel1->getReihen(reihenKarten,Reihenlaenge);
    for(int i = 0;i<AnzahlKIs;i++){
       KIPlay[i] =  pKI[i].askCard(reihenKarten,Reihenlaenge);
    }

    delete[] reihenKarten;
    delete[] Reihenlaenge;

    this->isKITurn = false;
}

void GameManager::EvaluatePlayed()
{
    for(int i = 0;i<AnzahlKIs+1;i++){
        if(i<AnzahlKIs) {
            sortiert[i] = KIPlay[i];
                                                                                std::cout << sortiert[i].getPosition().y << std::endl;
//            sortiert[i].setCard(sortiert[i].getValue());
        } else {
            sortiert[i] = *SpielerPlay;
                                                                                std::cout << sortiert[i].getPosition().y << std::endl;
        }
    }
    sort(sortiert,sortiert+AnzahlKIs+1,sort_ByValue);

    //// Animations ////
    // load all played cards to the animations (after deleting the old cards)
    upAnimatedCards->clearCards();
    for(int i = 0;i<AnzahlKIs+1;i++){
        upAnimatedCards->addCard(sortiert[i],CalculateTargetPosition(i));
    }
    ////////////////////


    this->ShowPlayed();

    // Karten anlegen
    for(int i = 0;i<AnzahlKIs+1;i++){
        if(sortiert[i].getSpielerNr() == 1){
            pSpieler1->addHornochsen(pSpiel1->anlegen(sortiert[i]));
        } else {
            pKI[sortiert[i].getSpielerNr()-2].addHornochsen(pSpiel1->anlegen(sortiert[i]));
        }
    }
}

void GameManager::ShowHornochsenStatus()
{
    std::stringstream ssTextString;
    ssTextString << "Deine Hornochsen: " << pSpieler1->getHornochsen() << std::endl;
    for(int i = 0;i<AnzahlKIs;i++){
        ssTextString << "KI-" << pKI[i].getSpielerNr()-1 << "Hornochsen: " << pKI[i].getHornochsen() << std::endl;
    }
    std::string TextString = ssTextString.str();
    StatusText->setString(TextString);

    StatusRect.setSize(sf::Vector2f(290, StatusText->getGlobalBounds().height));
}

void GameManager::ShowPlayed()
{
//    //Print to Window
//    std::stringstream ssPlayedString;
//    for(int i = 0;i<AnzahlKIs+1;i++){
//        if(sortiert[i].getSpielerNr() == 1){
//            ssPlayedString << "You played: " << sortiert[i].getValue() << std::endl;
//        } else {
//            ssPlayedString << "KI-" << sortiert[i].getSpielerNr()-1 << "played: " << sortiert[i].getValue() << std::endl;
//        }
//    }
//    std::string PlayedString = ssPlayedString.str();
//    PlayedText->setString(PlayedString);

    PlayedText->setString("Cards Played");
    PlayedText->setPosition(constants::WindowW - constants::CardW*1.3,5);
    PlayedRect.setFillColor(sf::Color::Cyan);
    PlayedRect.setPosition(constants::WindowW - constants::CardW*1.4,0);
    PlayedRect.setSize(sf::Vector2f(275, constants::WindowH));

    //Print to Console
    for(int i = 0;i<AnzahlKIs+1;i++){
        if(sortiert[i].getSpielerNr() == 1){
            cout << "You played: " << sortiert[i].getValue() << endl;
        } else {
            cout << "KI-"<< sortiert[i].getSpielerNr()-1 << " played: " << sortiert[i].getValue() << endl;
        }
    }
    cout << endl;
}

sf::Vector2f GameManager::CalculateTargetPosition(int OrderPosition)
{
    float SpacingH = 1.1 - ResourceManager::getKINumber()*(1.1-0.25)/9.0 ;
    float SpacingW = 1.2;

    sf::Vector2f Target;

    Target.x = constants::WindowW - constants::CardW*SpacingW;
    Target.y = 50 + OrderPosition*constants::CardH*SpacingH;

    return Target;
}
