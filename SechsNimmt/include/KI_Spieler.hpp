#ifndef KI_SPIELER_HPP//_INCLUDED
#define KI_SPIELER_HPP//_INCLUDED

#include <iostream>

#include "Spieler.hpp"
#include "card.hpp"

class KI_Spieler: public Spieler
{
    public:
//        KI_Spieler();
        KI_Spieler();

        void setnr(int KInr) {mKInr = KInr;};

        void giveUpdate();

        card askCard(const card Reihen[4*5], const int Reihenlaenge[]);

    private:
        int mKInr;
};


#endif // KI_SPIELER_HPP_INCLUDED
