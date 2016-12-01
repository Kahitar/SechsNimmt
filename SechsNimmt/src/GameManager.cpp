#include "GameManager.hpp"

GameManager::GameManager()
{
    cout << "Mit wie vielen KI-Gegnern moechtest du spielen? (0-9): ";
    AnzahlKIs = 3;//cin >> AnzahlKIs;
    cout << AnzahlKIs << endl << endl;
    AnzahlStartkarten = 10;

    font            = new sf::Font;
    font->loadFromFile("Resources\\PAPYRUS.TTF");
    StatusText      = new sf::Text;
    StatusText->setFont(*font);
    StatusText->setCharacterSize(25);
    StatusText->setColor(sf::Color::Black);
    StatusText->setPosition(sf::Vector2f(30,300));
    StatusText->setStyle(sf::Text::Bold);

    PlayedText      = new sf::Text;
    PlayedText->setFont(*font);
    PlayedText->setCharacterSize(25);
    PlayedText->setColor(sf::Color::Green);
    PlayedText->setPosition(sf::Vector2f(1300,450));
    PlayedText->setStyle(sf::Text::Bold);

    sortiert        = new card[AnzahlKIs+1];
    isPlayerTurn    = true;
    isKITurn        = true;

    pGameDeck       = new deck;
    pSpiel1         = new Reihen;
    pSpieler1       = new Spieler("Niklas",1);
    pKI             = new KI_Spieler[AnzahlKIs];

    SpielerWantPlay = new card;
    SpielerPlay     = new card;
    KIPlay          = new card[AnzahlKIs];
//    reihenKarten    = new card[4*5]; //---> moved to KITurn()
//    Reihenlaenge    = new int[4];

    // Deck initialisieren und mischen
    pGameDeck->mischen();
    for(int i = 0;i<AnzahlKIs;i++){
        pKI[i].setnr(i);
        pKI[i].setSpielerNr(i+2);
    }

    // Karten an Spieler, KI und Reihen austeilen
    card *ForRows;
    ForRows = new card[4];
    for(int i = 0;i<AnzahlStartkarten;i++){
        pSpieler1->giveCard(pGameDeck->austeilen()); //Copy, Assign, Delete
        for(int j = 0;j < AnzahlKIs;j++){
            pKI[j].giveCard(pGameDeck->austeilen());
        }
        if(i<4){
            ForRows[i] = pGameDeck->austeilen(); //Copy, Assign, Delete
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

    pSpiel1->printReihen();
    pSpieler1->giveUpdate();
}

void GameManager::update()
{
    // KI Spielen lassen und Karten anlegen, wenn der Spieler NICHT am Zug ist, danach ist der Spieler wieder am Zug.
    if(!pSpieler1->getPlayerTurn())
    {
        if(isKITurn){
            KITurn();
        }
        EvaluatePlayed();//isPlayerTurn = EvaluatePlayed();
        //isKITurn = isPlayerTurn;


        // Sieger ausgeben
        if(!pSpieler1->getNumberCards()){
            pSpiel1->printReihen();
            cout << "The Game is over!\n\nYou have " << pSpieler1->getHornochsen() << " Hornochsen!\n\n";

            for(int i = 0;i<AnzahlKIs;i++){
                cout << "KI-" << pKI[i].getSpielerNr()-1 << " has " << pKI[i].getHornochsen() << " Hornochsen!\n";
            }
        }

        if(isPlayerTurn){
            pSpieler1->setTurn();
            pSpiel1->printReihen();
            pSpieler1->giveUpdate();
        }
    }


    pSpieler1->update();
    pSpiel1->update();

//    for(int i = 0;i<AnzahlKIs+1;i++){
//        sortiert[i].update();
//    }

    std::stringstream ssTextString;
    ssTextString << "Deine Hornochsen: " << pSpieler1->getHornochsen() << std::endl;
    for(int i = 0;i<AnzahlKIs;i++){
        ssTextString << "KI-" << pKI[i].getSpielerNr()-1 << "Hornochsen: " << pKI[i].getHornochsen() << std::endl;
    }
    std::string TextString = ssTextString.str();

    StatusText->setString(TextString);
}

void GameManager::handle(sf::Event *event)
{
    // Wenn der Spieler klickt, überprüfen ob die Maus auf einer Karte war und wenn ja diese Karte Spielen
    if(pSpieler1->getPlayerTurn() && event->type == sf::Event::MouseButtonPressed && event->mouseButton.button == sf::Mouse::Left){
        // Nach zu spielenden Karten fragen
        SpielerWantPlay = pSpieler1->askCard(event);
        if(!pSpieler1->getPlayerTurn()){
            *SpielerPlay = *SpielerWantPlay;
        }
    }
    // Wenn Spieler keine neue Karte gespielt hat, ist nach handle() noch die ALTE Karte im Zeiger "SpielerPlay" und der Spieler ist noch am Zug


    pSpieler1->handle(event);
    pSpiel1->handle(event);
}

void GameManager::render(sf::RenderWindow *rw)
{
    pSpiel1->render(rw);
    pSpieler1->render(rw);
//    for(int i = 0;i<AnzahlKIs+1;i++){
//        sortiert[i].render(rw);
//    }

    rw->draw(*StatusText);
    rw->draw(*PlayedText);
}

void GameManager::KITurn(){

    reihenKarten    = new card[4*5];
    Reihenlaenge    = new int[4];

    pSpiel1->getReihen(reihenKarten,Reihenlaenge);
    for(int i = 0;i<AnzahlKIs;i++){
       KIPlay[i] =  pKI[i].askCard(reihenKarten,Reihenlaenge);
    }

    delete[] reihenKarten;
    delete[] Reihenlaenge;
}

void GameManager::EvaluatePlayed()
{
//    bool AnimationEnded = false;
//    AnimationEnded = MoveCardToHold(sortiert, AnzahlKIs+1);
//
//    if(AnimationEnded){
        //Zu spielende Karten nach Value (aufsteigend) sortieren
        for(int i = 0;i<AnzahlKIs+1;i++){
            if(i<AnzahlKIs) {
                sortiert[i] = KIPlay[i];
                sortiert[i].setCard(sortiert[i].getValue());
            } else {
                sortiert[i] = *SpielerPlay;
            }
        }
        sort(sortiert,sortiert+AnzahlKIs+1,sort_ByValue);

        std::stringstream ssPlayedString;
        for(int i = 0;i<AnzahlKIs+1;i++){
            if(sortiert[i].getSpielerNr() == 1){
                ssPlayedString << "You played: " << sortiert[i].getValue() << std::endl;
            } else {
                ssPlayedString << "KI-" << sortiert[i].getSpielerNr()-1 << "played: " << sortiert[i].getValue() << std::endl;
            }
        }
        std::string PlayedString = ssPlayedString.str();
        PlayedText->setString(PlayedString);


        for(int i = 0;i<AnzahlKIs+1;i++){
            if(sortiert[i].getSpielerNr() == 1){
                cout << "You played: " << sortiert[i].getValue() << endl;
            } else {
                cout << "KI-"<< sortiert[i].getSpielerNr()-1 << " played: " << sortiert[i].getValue() << endl;
            }
        }
        cout << endl;

        // Karten anlegen
        for(int i = 0;i<AnzahlKIs+1;i++){
            if(sortiert[i].getSpielerNr() == 1){
                pSpieler1->addHornochsen(pSpiel1->anlegen(sortiert[i]));
            } else {
                pKI[sortiert[i].getSpielerNr()-2].addHornochsen(pSpiel1->anlegen(sortiert[i]));
            }
        }

//        return true;    //Spieler kann weiterspielen
//    } else {
//        return false;   //Animation wird im nächsten Frame fortgesetzt, Spieler kann noch nicht weiterspielen
//    }
}

bool GameManager::MoveCardToHold(card ToPlay[], int Size)
{
    float CardW = 134.0, CardH = 205.0, WindowW = 1600.0;//, WindowH = 900.0;
    float SpacingH = 0.8, SpacingW = 1.5;

    sf::Vector2f    Target[Size];
    sf::Vector2f    Direction[Size];
    float           PathLength[Size];
    sf::Vector2f    DirectionUnit[Size];

    for(int i = 0;i<Size;i++){
        Target[i].x = WindowW - CardW*SpacingW;
        Target[i].y = i*CardH*SpacingH;

        Direction[i].x = Target[i].x - ToPlay[i].getPosition().x; //std::cout << "Directionvektor x: " << Target[i].x << std::endl;
        Direction[i].y = Target[i].y - ToPlay[i].getPosition().y; //std::cout << "Directionvektor y: " << Target[i].x << std::endl;

        PathLength[i] = sqrt(Direction[i].x * Direction[i].x + Direction[i].y * Direction[i].y);

        DirectionUnit[i].x = Direction[i].x/PathLength[i]/10;
        DirectionUnit[i].y = Direction[i].y/PathLength[i]/10;

        ToPlay[i].setMoving(DirectionUnit[i],PathLength[i]);
    }
    if(Direction[0].x < 300 && Direction[0].y < 300 && Direction[0].x > -300 && Direction[0].y > -300){
        return true; //Animation ended
    } else {
        return false;   //Animation didn't end yet!
    }
}
