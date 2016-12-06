#ifndef SPIELER_HPP_INCLUDED
#define SPIELER_HPP_INCLUDED

#include <iostream>

#include "SpielerVirtual.hpp"
#include "card.hpp"

using namespace std;

class Spieler:public SpielerVirtual
{
    public:
        Spieler(){};
        Spieler(string name, int number);
        ~Spieler();

        void    giveCard(card karte);
        void    addHornochsen(int neueHornochsen) {mHornochsen += neueHornochsen;};

        void    giveUpdate();

        sf::Vector2f GetCardPosition(int CardIndex);

        card* askCard(sf::Event *event);

};


#endif // SPIELER_HPP_INCLUDED
