#include <iostream>
#include <ctime>
#include <cstdlib>

#include "card.hpp"
#include "deck.hpp"
#include "KI_Spieler.hpp"


using namespace std;

KI_Spieler::KI_Spieler()
{
    mName = "KI";
    mHornochsen = 0;
    mNumberCards = 0;
    mSpielerNr = 0;
    play        = new card;
    mHandkarten = new card[10];
}

KI_Spieler::~KI_Spieler()
{
    delete play;
    delete[] mHandkarten;
}

void KI_Spieler::giveUpdate(){
    cout <<  "KI-" << mKInr+1 << ": ";
    for(int i = 0;i<mNumberCards;i++){
        if(i!=(mNumberCards-1)){
            cout << mHandkarten[i].getValue() << "[" << mHandkarten[i].getHornochsen() << "], ";
        } else {
            cout << mHandkarten[i].getValue() << "[" << mHandkarten[i].getHornochsen() << "] \n";
        }
    }
    cout << "Hornochsen: " << mHornochsen << "\n\n";
}

card KI_Spieler::askCard(const card Reihen[4*5], const int Reihenlaenge[]){
    // Karten-Reihen-Paar mit kleinster Differenz finden und entsprechende Karte spielen
    card play;
    int diff_min = 104;
    int diff = 0;
    int play_index = 0;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<mNumberCards;j++){
            diff = mHandkarten[j].getValue() - Reihen[i*5 + (Reihenlaenge[i]-1)].getValue();
            if(diff > 0 && diff < diff_min){
                play = mHandkarten[j];
                play_index = j;
                diff_min = diff;
            }
        }
    }

    // Wenn keine Karte mit positiver Differenz auf der Hand, kleinste Karte überhaupt spielen
    if(diff_min == 104){
        int kleinsteKarte_index = 0;
        play = mHandkarten[0];
        for(int i=0;i<mNumberCards;i++){
            if(mHandkarten[i].getValue() < mHandkarten[kleinsteKarte_index].getValue()){
                play = mHandkarten[i];
                play_index = i;
                kleinsteKarte_index = i;
            }
        }
    }

    // Zu spielende Karte aus der Hand löschen
    for(int i = play_index; i < mNumberCards-1;i++){
        if(i!=mNumberCards){
            mHandkarten[i] = mHandkarten[i+1];
        }
    }
    mNumberCards--;
    play.setSpielerNr(this->mSpielerNr);

    return play;
}

//void KI_Spieler::giveCard(card karte)
//{
//    mHandkarten[mNumberCards] = karte;
//    mHandkarten[mNumberCards].setCard(karte.getValue());
//    mHandkarten[mNumberCards].setPosition(GetCardPosition(mNumberCards));
//    mNumberCards++;
//}
