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
    card(const card& other);
    card& operator=(const card& other);

    void            update();
    void            handle(sf::Event *Event);
    void            render(sf::RenderWindow *rw);

    const sf::Vector2f    getPosition()   {return *pPosition;};
    const int             getValue()      {return mValue;};
    const int             getHornochsen() {return mHornochsen;};
    const int             getSpielerNr()  {return mSpielerNr;};
    const bool            getMouseOnCard(){return mMouseOnCard;};
    const bool            getPlayed()     {return played;};

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
