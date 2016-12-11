#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "card.hpp"
#include "deck.hpp"

using namespace std;

deck::deck()
{
    mAusgeteilt = 0;

    spDeck = std::unique_ptr<card[]>(new card[104]);

    for(int i = 0;i<104;i++){
        spDeck[i].setCard(i+1);
        DealNextIndex[i] = i;
    }
}

deck::~deck()
{

}

card deck::getCard(int a)
{
    return spDeck[a];
}

void deck::mischen()
{
    srand(time(0)+rand());
    int Puffer;
    int random1,random2;
    for(int i = 0;i<200;i++){
        random1 = rand()%104;
        random2 = rand()%104;
        Puffer = DealNextIndex[random1];
        DealNextIndex[random1] = DealNextIndex[random2];
        DealNextIndex[random2] = Puffer;
    }
    mAusgeteilt = 0;
}

card deck::austeilen()
{
    card give = spDeck[DealNextIndex[mAusgeteilt]];
    mAusgeteilt++;
    return give;
}
