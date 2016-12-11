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

#include "card.hpp"
#include "Spieler.hpp"
#include "KI_Spieler.hpp"
#include "Reihen.hpp"
#include "functions.hpp"
#include "Button.hpp"

#include "Gamestate.hpp"

class Framework;
class deck;

class GameManager : public Gamestate
{
public:
     GameManager(int NumberKIs);
    ~GameManager();

    void update(Framework &frmwrk);
    void handle(Framework &frmwrk);
    void render(Framework &frmwrk);

private:
    void KITurn();
    void EvaluatePlayed();
    bool MoveCardToHold(card ToPlay[], int Size);

    int AnzahlStartkarten;
    int AnzahlKIs;

    std::shared_ptr<deck> pGameDeck;
    Spieler         *pSpieler1;
    KI_Spieler      *pKI;
    Reihen          *pSpiel1;

    card            *SpielerWantPlay;
    card            *SpielerPlay;
    card            *KIPlay;
    card            *sortiert;

    card            *reihenKarten;
    int             *Reihenlaenge;

    std::shared_ptr<sf::Font> font;
//    sf::Font        *font;
    sf::Text        *StatusText;
    sf::Text        *PlayedText;

    bool isPlayerTurn;
    bool isKITurn;

    std::unique_ptr<Button> upMainMenuButton;
};


#endif // GAMEMANAGER_HPP
