#include "GameManager.hpp"


GameManager::GameManager()//:pSpieler1("Niklas",1)
{
    cout << "Mit wie vielen KI-Gegnern moechtest du spielen? (0-9): ";
    AnzahlKIs = 1;//cin >> AnzahlKIs;
    cout << AnzahlKIs << endl << endl;
    AnzahlStartkarten = 10;

    pGameDeck       = new deck;
    pSpiel1         = new Reihen;
    pSpieler1       = new Spieler("Niklas",1);
    pKI             = new KI_Spieler[AnzahlKIs];

//    SpielerWantPlay = new card;
//    SpielerPlay     = new card;
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
        KITurn();
        EvaluatePlayed();

        // Sieger ausgeben
        if(!pSpieler1->getNumberCards()){
            pSpiel1->printReihen();
            cout << "The Game is over!\n\nYou have " << pSpieler1->getHornochsen() << " Hornochsen!\n\n";

            for(int i = 0;i<AnzahlKIs;i++){
                cout << "KI-" << pKI[i].getSpielerNr()-1 << " has " << pKI[i].getHornochsen() << " Hornochsen!\n";
            }
        }
        pSpieler1->setTurn();

        pSpiel1->printReihen();
        pSpieler1->giveUpdate();
    }


    pSpieler1->update();
    pSpiel1->update();
}

void GameManager::handle(sf::Event *event)
{
    // Wenn der Spieler klickt, überprüfen ob die Maus auf einer Karte war und wenn ja diese Karte Spielen
    if(pSpieler1->getPlayerTurn() && event->type == sf::Event::MouseButtonPressed && event->mouseButton.button == sf::Mouse::Left){
        // Nach zu spielenden Karten fragen
        SpielerWantPlay = pSpieler1->askCard(event);
        if(!pSpieler1->getPlayerTurn()){
            SpielerPlay = SpielerWantPlay;
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

void GameManager::EvaluatePlayed(){

    //Zu spielende Karten nach Value (aufsteigend) sortieren
    card sortiert[AnzahlKIs+1];
//    sortiert = new card[AnzahlKIs + 1];
    for(int i = 0;i<AnzahlKIs+1;i++){
        if(i<AnzahlKIs) {
            sortiert[i] = KIPlay[i];
        } else {
            sortiert[i] = SpielerPlay;
        }
    }
    sort(sortiert,sortiert+AnzahlKIs+1,sort_ByValue);
    cout << endl;

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
//        if(sortiert[i].getSpielerNr() == 1){
//            pSpieler1->addHornochsen(pSpiel1->anlegen(sortiert[i]));
//        } else {
//            pKI[i-2].addHornochsen(pSpiel1->anlegen(sortiert[i]));
//        }
        switch(sortiert[i].getSpielerNr()){
            case 1: pSpieler1->addHornochsen(pSpiel1->anlegen(sortiert[i])); break;
            case 2: pKI[0].addHornochsen(pSpiel1->anlegen(sortiert[i])); break;
            case 3: pKI[1].addHornochsen(pSpiel1->anlegen(sortiert[i])); break;
            case 4: pKI[2].addHornochsen(pSpiel1->anlegen(sortiert[i])); break;
            case 5: pKI[3].addHornochsen(pSpiel1->anlegen(sortiert[i])); break;
            case 6: pKI[4].addHornochsen(pSpiel1->anlegen(sortiert[i])); break;
            case 7: pKI[5].addHornochsen(pSpiel1->anlegen(sortiert[i])); break;
            case 8: pKI[6].addHornochsen(pSpiel1->anlegen(sortiert[i])); break;
            case 9: pKI[7].addHornochsen(pSpiel1->anlegen(sortiert[i])); break;
            case 10: pKI[8].addHornochsen(pSpiel1->anlegen(sortiert[i])); break;
        }
    }
}
