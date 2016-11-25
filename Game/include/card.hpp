#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

class card
{
public:
    card();
    ~card();

    void            update();
    void            handle(sf::Event *Event);
    void            render(sf::RenderWindow *rw);

    sf::Vector2f    getPosition()   {return *pPosition;};
    int             getValue()      {return mValue;};
    int             getHornochsen() {return mHornochsen;};
    int             getSpielerNr()  {return mSpielerNr;};
    bool            getMouseOnCard(){return mMouseOnCard;};
    bool            getPlayed()     {return played;};

    void            setSpielerNr(int SpielerNr);
    void            setPosition(sf::Vector2f Position);
    void            setCard(int value);
    void            setPlayed(bool setter) {played = setter;};

private:
    void            LoadCardTexture(int CardValue);

    sf::Vector2f    *pPosition;
    sf::Texture     *pTexture;
    sf::Sprite      *pSprite;

    sf::Texture     *pBlackTexture;
    sf::Sprite      *pBlackSprite;

    bool            mMouseOnCard;

    int             mValue;
    int             mHornochsen;
    int             mSpielerNr;

    int             played;

};

#endif // CARD_HPP
