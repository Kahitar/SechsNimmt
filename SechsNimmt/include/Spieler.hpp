#ifndef SPIELER_HPP_INCLUDED
#define SPIELER_HPP_INCLUDED

#include <iostream>

#include "card.hpp"

using namespace std;

class Spieler
{
    public:
        Spieler(){};
        Spieler(string name, int number);
        virtual ~Spieler();


        void    giveCard(card karte);
        void    addHornochsen(int neueHornochsen) {mHornochsen += neueHornochsen;};

        void    setSpielerNr(int SpNr)  {mSpielerNr = SpNr;};
        void    setName(string name)    {mName = name;};
        void    setTurn()               {PlayerTurn = true;};

        int     getNumberCards() {return mNumberCards;};
        int     getHornochsen()  {return mHornochsen;};
        int     getSpielerNr()   {return mSpielerNr;};
        bool    getPlayerTurn()  {return PlayerTurn;};
        string  getName()        {return mName;};

        void    giveUpdate();
        void    sortCards();
        card*   askCard(sf::Event *event);

        void    update();
        void    handle(sf::Event *event);
        void    render(sf::RenderWindow *rw);

    private:
        sf::Vector2f GetCardPosition(int CardIndex);

    protected:
        string  mName;
        int     mHornochsen;
        int     mNumberCards;
        int     mSpielerNr;
        card    *mHandkarten;

        bool    PlayerTurn;

        card    *play;
};


#endif // SPIELER_HPP_INCLUDED
