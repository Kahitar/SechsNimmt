#include <iostream>
#include <algorithm>

#include "SpielerVirtual.hpp"
#include "card.hpp"

void SpielerVirtual::update()
{
    //Handkarten hervorheben
    for(int i = 0;i<mNumberCards;i++)
        mHandkarten[i].update();
}

void SpielerVirtual::handle(sf::Event *event)
{
    for(int i = 0;i<mNumberCards;i++)
        mHandkarten[i].handle(event);
}

void SpielerVirtual::render(sf::RenderWindow *rw)
{
    //Handkarten zeichnen
    for(int i = 0;i<mNumberCards;i++)
        mHandkarten[i].render(rw);
}

sf::Vector2f SpielerVirtual::GetCardPosition(int CardIndex)
{
    float CardW = 134.0, CardH = 205.0, WindowW = 1600.0, WindowH = 800.0;
    float SpacingW = 1.0;

    sf::Vector2f Position;
    Position.x = (WindowW-10.0*CardW*SpacingW)/2.0 + CardIndex*CardW*SpacingW;
    Position.y = WindowH-CardH/2;

    return Position;
}

void SpielerVirtual::giveUpdate()
{
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
