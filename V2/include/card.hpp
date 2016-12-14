#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

#include <memory>

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

    const sf::Vector2f    getPosition()         const {return *pPosition;};
    const int             getValue()            const {return mValue;};
    const int             getHornochsen()       const {return mHornochsen;};
    const int             getSpielerNr()        const {return mSpielerNr;};
    const bool            getMouseOnCard()      const {return mMouseOnCard;};
    const bool            getMovestatus()       const {return mMoving;};
    const sf::Vector2f    getMoveDirection()    const {return mMoveDirection;};

    void            setSpielerNr(int SpielerNr);
    void            setPosition(sf::Vector2f Position);
    void            setCard(int value);
    void            setMoving(sf::Vector2f Direction, int pathLength);
    void            setValue(int value){mValue = value;};

private:
    void            LoadCardTexture(int CardValue);

    std::shared_ptr<sf::Vector2f> pPosition;
    std::shared_ptr<sf::Texture>  pTexture;
    std::shared_ptr<sf::Sprite>   pSprite;

    std::shared_ptr<sf::Texture>  pBlackTexture;
    std::shared_ptr<sf::Sprite>   pBlackSprite;

    bool            mMouseOnCard;
    bool            mMoving;
    sf::Vector2f    mMoveDirection;

    int             mValue;
    int             mHornochsen;
    int             mSpielerNr;

};

#endif // CARD_HPP
