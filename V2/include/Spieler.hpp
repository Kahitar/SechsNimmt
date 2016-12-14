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

        void giveCard(card karte);
        void sortCards();
        void addHornochsen(int neueHornochsen) {mHornochsen += neueHornochsen;};

        card* askCard(sf::Event *event);

        sf::Vector2f GetCardPosition(int CardIndex);
        void giveUpdate();
};

#endif // SPIELER_HPP_INCLUDED
