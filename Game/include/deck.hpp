#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>

#include "card.hpp"

class deck
{
    public:
        deck();
        ~deck();

        void mischen();
        card austeilen();

        card getCard(int a) {return pDeck[a];};

    protected:

    private:
        card *pDeck;
        int mAusgeteilt;
};

#endif // DECK_HPP
