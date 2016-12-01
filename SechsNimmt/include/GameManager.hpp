#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "deck.hpp"
#include "card.hpp"
#include "Spieler.hpp"
#include "KI_Spieler.hpp"
#include "Reihen.hpp"

#include "functions.hpp"

class GameManager
{
public:
     GameManager();
    ~GameManager(){};

    void update();
    void handle(sf::Event *event);
    void render(sf::RenderWindow *rw);

private:
    void KITurn();
    void EvaluatePlayed();
    bool MoveCardToHold(card ToPlay[], int Size);

    int AnzahlStartkarten;
    int AnzahlKIs;

    deck            *pGameDeck;
    Reihen          *pSpiel1;
    Spieler         *pSpieler1;
    KI_Spieler      *pKI;

    card            *SpielerWantPlay;
    card            *SpielerPlay;
    card            *KIPlay;
    card            *sortiert;

    card            *reihenKarten;
    int             *Reihenlaenge;

    sf::Font        *font;
    sf::Text        *StatusText;

    bool isPlayerTurn;
    bool isKITurn;
};


#endif // GAMEMANAGER_HPP
