#ifndef KI_SPIELER_HPP
#define KI_SPIELER_HPP

#include <iostream>

#include "SpielerVirtual.hpp"
#include "card.hpp"

class KI_Spieler: public SpielerVirtual
{
    public:
        KI_Spieler();
        ~KI_Spieler();

        void setnr(int KInr) {mKInr = KInr;};

        void giveUpdate();

        card askCard(const card Reihen[4*5], const int Reihenlaenge[]);

//        void giveCard(card karte);

        void    addHornochsen(int neueHornochsen) {mHornochsen += neueHornochsen;};

    private:
        int mKInr;
};


#endif // KI_SPIELER_HPP
