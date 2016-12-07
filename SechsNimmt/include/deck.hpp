#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <memory>

#include "card.hpp"


class deck
{
    public:
        deck();
        ~deck();

        void mischen();
        card austeilen();

        card getCard(int a);

    protected:

    private:
        std::unique_ptr<card[]> spDeck;//card *pDeck;
        int mAusgeteilt;

        int DealNextIndex[104];
};

#endif // DECK_HPP
