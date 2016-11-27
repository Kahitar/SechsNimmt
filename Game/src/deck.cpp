#include <iostream>
#include <ctime>
#include <cstdlib>

#include "card.hpp"
#include "deck.hpp"

using namespace std;

deck::deck(){
    mAusgeteilt = 0;

    pDeck = new card[104];

    for(int i = 1;i<105;i++){
        pDeck[i-1].setCard(i);
    }
}

card deck::getCard(int a) {
    return pDeck[a];
}

deck::~deck(){
    delete pDeck;
    pDeck = NULL;
}

void deck::mischen(){
    srand(time(0)+rand());
    card Puffer;
    int random1,random2;
    for(int i = 0;i<100;i++){
        random1 = rand()%104;
        random2 = rand()%104;
        Puffer = pDeck[random1];
        pDeck[random1] = pDeck[random2];
        pDeck[random2] = Puffer;
    }
}

card deck::austeilen(){
    card give(pDeck[mAusgeteilt]);
    mAusgeteilt++;
    return give;
}
