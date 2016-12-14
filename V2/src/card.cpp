#include "card.hpp"
#include "ResourceManager.hpp"

card::card()
    :mMouseOnCard(false),mMoving(false),mSpielerNr(0)
{
    pPosition   = std::shared_ptr<sf::Vector2f>(new sf::Vector2f);
    pTexture    = std::shared_ptr<sf::Texture>(new sf::Texture);
    pSprite     = std::shared_ptr<sf::Sprite>(new sf::Sprite);

    pBlackTexture   = std::shared_ptr<sf::Texture>(new sf::Texture);
    pBlackSprite    = std::shared_ptr<sf::Sprite>(new sf::Sprite);

    pPosition->x    = -134;
    pPosition->y    = -205;

    *pBlackTexture  = ResourceManager::getTexture("Resources\\CardBlack.png");
    pBlackSprite->setTexture(*pBlackTexture);
}

card::~card()
{

}

card::card(const card& other)
    :mMouseOnCard(other.mMouseOnCard),mMoving(other.mMoving),mValue(other.mValue),mHornochsen(other.mHornochsen),mSpielerNr(other.mSpielerNr)
{
    pPosition       = std::shared_ptr<sf::Vector2f> (new sf::Vector2f);
    pTexture        = std::shared_ptr<sf::Texture>  (new sf::Texture);
    pSprite         = std::shared_ptr<sf::Sprite>   (new sf::Sprite);

    pBlackTexture   = std::shared_ptr<sf::Texture>  (new sf::Texture);
    pBlackSprite    = std::shared_ptr<sf::Sprite>   (new sf::Sprite);

    *pPosition      = *other.pPosition;
    *pTexture       = *other.pTexture;
    *pSprite        = *other.pSprite;

    *pBlackTexture  = *other.pBlackTexture;
    *pBlackSprite   = *other.pBlackSprite;
}

card& card::operator=(const card& other) // other = old card object (right hand side)
{
    if (this != &other) // protect against invalid self-assignment
    {
        pPosition       = std::shared_ptr<sf::Vector2f> (new sf::Vector2f);
        pTexture        = std::shared_ptr<sf::Texture>  (new sf::Texture);
        pSprite         = std::shared_ptr<sf::Sprite>   (new sf::Sprite);

        pBlackTexture   = std::shared_ptr<sf::Texture>  (new sf::Texture);
        pBlackSprite    = std::shared_ptr<sf::Sprite>   (new sf::Sprite);

        *pPosition      = *other.pPosition;
        *pTexture       = *other.pTexture;
        *pSprite        = *other.pSprite;
        *pBlackTexture  = *other.pBlackTexture;
        *pBlackSprite   = *other.pBlackSprite;

        mMouseOnCard    = other.mMouseOnCard;
        mMoving         = other.mMoving;
        mValue          = other.mValue;
        mHornochsen     = other.mHornochsen;
        mSpielerNr      = other.mSpielerNr;

        pSprite->setTexture(*pTexture);
        pBlackSprite->setTexture(*pBlackTexture);
    }

    return *this;
}

void card::update()
{
    if(mMoving){ //Move Cards to specific position (animated)
        pSprite->move(mMoveDirection);
        pBlackSprite->move(mMoveDirection);
        std::cout << "Moving!\n";
        std::cout << pSprite->getPosition().x << "\n";
    } else { //Highlight cards on players hand
        if(mMouseOnCard && pSprite->getPosition().y > pPosition->y-30){
            pSprite->move(0,-1);
            pBlackSprite->move(0,-1);
        } else if (!mMouseOnCard && pSprite->getPosition().y < pPosition->y){
            pSprite->move(0,1);
            pBlackSprite->move(0,1);
        }
    }
}

void card::handle(sf::Event *Event)
{
    if (Event->type == sf::Event::MouseMoved)
    {
        if(Event->mouseMove.x > pSprite->getPosition().x
           && Event->mouseMove.y > pSprite->getPosition().y
           && Event->mouseMove.x < pSprite->getPosition().x+134
           && Event->mouseMove.y < pPosition->y+204)
        {
            mMouseOnCard = true;
        } else{
            mMouseOnCard = false;
        }
    }
}

void card::render(sf::RenderWindow *rw)
{
    rw->draw(*pBlackSprite);
    rw->draw(*pSprite);
}

void card::LoadCardTexture(int CardValue)
{
    std::string Filedirectory = "Resources\\";
    std::string File;
    std::string FileType = ".png";

    int coordsx=0,coordsy=0;
    if(CardValue < 11) {
        File = "Cards1-10";
        if((CardValue-1)%10 < 5){
            coordsy = 0;
            coordsx = (4 - (CardValue-1)%5)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-1)%5)*134;
        }
    } else if (CardValue < 21) {
        File = "Cards11-20";
        if((CardValue-1)%10 < 5){
            coordsy = 0;
            coordsx = (4 - (CardValue-1)%5)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-1)%5)*134;
        }
    } else if (CardValue < 31) {
        File = "Cards21-30";
        if((CardValue-1)%10 < 5){
            coordsy = 0;
            coordsx = (4 - (CardValue-1)%5)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-1)%5)*134;
        }
    } else if (CardValue < 41) {
        File = "Cards31-40";
        if((CardValue-1)%10 < 5){
            coordsy = 0;
            coordsx = (4 - (CardValue-1)%5)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-1)%5)*134;
        }
    } else if (CardValue < 51) {
        File = "Cards41-50";
        if((CardValue-1)%10 < 5){
            coordsy = 0;
            coordsx = (4 - (CardValue-1)%5)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-1)%5)*134;
        }
    } else if (CardValue < 61) {
        File = "Cards51-60";
        if((CardValue-1)%10 < 5){
            coordsy = 0;
            coordsx = (4 - (CardValue-1)%5)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-1)%5)*134;
        }
    } else if (CardValue < 71) {
        File = "Cards61-70";
        if((CardValue-1)%10 < 5){
            coordsy = 0;
            coordsx = (4 - (CardValue-1)%5)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-1)%5)*134;
        }
    } else if (CardValue < 81) {
        File = "Cards71-80";
        if((CardValue-1)%10 < 5){
            coordsy = 0;
            coordsx = (4 - (CardValue-1)%5)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-1)%5)*134;
        }
    } else if (CardValue < 91) {
        File = "Cards81-90";
        if((CardValue-1)%10 < 5){
            coordsy = 0;
            coordsx = (4 - (CardValue-1)%5)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-1)%5)*134;
        }
    } else if (CardValue < 101) {
        File = "Cards91-100";
        if((CardValue-1)%10 < 5){
            coordsy = 0;
            coordsx = (4 - (CardValue-1)%5)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-1)%5)*134;
        }
    } else {
        File = "Cards101-104";
        if((CardValue-1)%10 < 5){
            coordsy = 0;
            coordsx = (4 - (CardValue-1)%5)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-1)%5)*134;
        }
    }

    std::stringstream ssfilepath;
    ssfilepath << Filedirectory << File << FileType;
    std::string filepath = ssfilepath.str();

    *pTexture  = ResourceManager::getTexture(filepath);//pTexture->loadFromFile(filename);
    pSprite->setTexture(*pTexture);

    pSprite->setTextureRect(sf::IntRect(coordsx,coordsy,134,204));
//    pSprite->setPosition(sf::Vector2f(300, 200));
}

void card::setCard(int value)
{
    mValue = value;
    LoadCardTexture(mValue);

    if(mValue == 55){
        mHornochsen = 7;
    } else if((mValue%10) == 0){
        mHornochsen = 3;
    } else if(mValue == 11||mValue == 22||mValue == 33||mValue == 44||mValue == 66||mValue == 77||mValue == 88||mValue == 99){
        mHornochsen = 5;
    } else if((mValue%5) == 0){
        mHornochsen = 2;
    } else {
        mHornochsen = 1;
    }
}

void card::setSpielerNr(int SpielerNr)
{
    mSpielerNr = SpielerNr;
}

void card::setPosition(sf::Vector2f newPosition)
 {
     *pPosition = newPosition;
     pSprite->setPosition(*pPosition);
     pBlackSprite->setPosition(sf::Vector2f(pPosition->x - 5,pPosition->y - 5));
     pBlackSprite->setColor(sf::Color(255,255,255,150));
 }

void card::setMoving(sf::Vector2f Direction, int pathLength)
{
    mMoveDirection = Direction;
    mMoving = true;
}
