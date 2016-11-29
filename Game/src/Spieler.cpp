#include <iostream>
#include <algorithm>

#include "Spieler.hpp"
#include "functions.hpp"
#include "card.hpp"

Spieler::Spieler(string name="KI", int SpielerNr = 0)
:mName(name),mHornochsen(0),mNumberCards(0),mSpielerNr(SpielerNr)
{
    play        = new card;
    mHandkarten = new card[10];
}


void Spieler::giveCard(card karte){
    mHandkarten[mNumberCards] = karte;
    mHandkarten[mNumberCards].setPosition(GetCardPosition(mNumberCards));
    mNumberCards++;
}

void Spieler::giveUpdate(){
    cout <<  "Your Cards: ";
    for(int i = 0;i<mNumberCards;i++){
        if(i!=(mNumberCards-1)){
            cout << mHandkarten[i].getValue() << "[" << mHandkarten[i].getHornochsen() << "], ";
        } else {
            cout << mHandkarten[i].getValue() << "[" << mHandkarten[i].getHornochsen() << "] \n";
        }
    }
    cout << "Your Hornochsen: " << mHornochsen << "\n\n";
}

card Spieler::askCard(sf::Event *event){

    int a;
    int play_index = 0;

    // Wenn die Maus auf einer Karte war, diese Karte zurückgeben und Spieler ist nicht mehr am Zug
    for(int i = 0;i<mNumberCards;i++){
        if(mHandkarten[i].getMouseOnCard()){
            a = mHandkarten[i].getValue();
            play_index = i;
            for(int j = play_index; j < mNumberCards-1;j++){
                mHandkarten[j] = mHandkarten[j+1];
            }
            this->mNumberCards--;
            for(int j = 0;j<mNumberCards;j++)
                mHandkarten[j].setPosition(GetCardPosition(j));

            this->PlayerTurn = false;
            play->setCard(a);
            play->setSpielerNr(mSpielerNr);
            std::cout << "You should play " << play->getValue() << endl;
            return *play;
        }
    }

    // Wenn die Maus auf keiner Karte war, eine Dummy-Karte zurückgeben
    return *play;
}

void Spieler::sortCards(){
    sort(mHandkarten,mHandkarten+mNumberCards,sort_ByValue);
    for(int i = 0;i<10;i++){
        mHandkarten[i].setPosition(GetCardPosition(i));
    }
}

void Spieler::update()
{
    //Handkarten hervorheben
    for(int i = 0;i<mNumberCards;i++)
        mHandkarten[i].update();
}

void Spieler::handle(sf::Event *event)
{
    for(int i = 0;i<mNumberCards;i++)
        mHandkarten[i].handle(event);
}

void Spieler::render(sf::RenderWindow *rw)
{
    //Handkarten zeichnen
    for(int i = 0;i<mNumberCards;i++)
        mHandkarten[i].render(rw);
}

sf::Vector2f Spieler::GetCardPosition(int CardIndex)
{
    float CardW = 134.0, CardH = 205.0, WindowW = 1600.0, WindowH = 900.0;
    float SpacingW = 1.0;

    sf::Vector2f Position;
    Position.x = (WindowW-10.0*CardW*SpacingW)/2.0 + CardIndex*CardW*SpacingW;
    Position.y = WindowH-CardH/2;

    return Position;
}
