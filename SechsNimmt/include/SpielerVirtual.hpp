#ifndef SPIELERVIRTUAL_HPP_INCLUDED
#define SPIELERVIRTUAL_HPP_INCLUDED

#include <iostream>

#include "card.hpp"

using namespace std;

class SpielerVirtual
{
    public:
        virtual         ~SpielerVirtual() {};

        virtual void    giveCard(card karte) ;//= 0;
        virtual void    addHornochsen(int neueHornochsen) = 0;

        void    setSpielerNr(int SpNr)  {mSpielerNr = SpNr;};
        void    setName(string name)    {mName = name;};
        void    setTurn()               {PlayerTurn = true;};

        int     getNumberCards() {return mNumberCards;};
        int     getHornochsen()  {return mHornochsen;};
        int     getSpielerNr()   {return mSpielerNr;};
        bool    getPlayerTurn()  {return PlayerTurn;};
        string  getName()        {return mName;};

        virtual void    giveUpdate() = 0;
        void    sortCards();

        void    update();
        void    handle(sf::Event *event);
        void    render(sf::RenderWindow *rw);

    //private:
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

#endif // SPIELERVIRTUAL_HPP_INCLUDED
