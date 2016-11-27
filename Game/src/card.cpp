#include "card.hpp"

card::card()
{
    mMouseOnCard    = false;
    pPosition       = new sf::Vector2f;
    pPosition->x    = 0;
    pPosition->y    = 0;

    pTexture        = new sf::Texture;
    pSprite         = new sf::Sprite;

    pBlackTexture   = new sf::Texture;
    pBlackTexture->loadFromFile("Resources\\CardBlack.png");
    pBlackSprite    = new sf::Sprite;
    pBlackSprite->setTexture(*pBlackTexture);

    std::cout << "Constructed!\n";
}

card::~card()
{
// Deleting these will result in program crash. Why?? - Weil ich das Wissen um den Copy-Constructor noch nicht überall eingebaut habe??
    delete pSprite;
    pSprite = NULL;
    delete pTexture;
    pTexture = NULL;
    delete pBlackSprite;
    pBlackSprite = NULL;
    delete pBlackTexture;
    pBlackTexture = NULL;
    delete pPosition;
    pPosition = NULL;
    std::cout << "Deleted!\n";
}

card::card(const card& other)
    :pPosition(new sf::Vector2f),pTexture(new sf::Texture),pSprite(new sf::Sprite),pBlackTexture(new sf::Texture),pBlackSprite(new sf::Sprite)
    ,mMouseOnCard(other.mMouseOnCard),mValue(other.mValue),mHornochsen(other.mHornochsen),mSpielerNr(other.mSpielerNr)
{
    *pPosition = *other.pPosition;
    *pTexture = *other.pTexture;
    *pSprite = *other.pSprite;

    *pBlackTexture = *other.pBlackTexture;
    *pBlackSprite = *other.pBlackSprite;

    std::cout << "Copied!\n";
}

//Copy assignment operator?! Is this right?
card& card::operator=(const card& other) // other = old card objekt
{
    if (this != &other) // protect against invalid self-assignment
    {
        pPosition       = new sf::Vector2f;
        pTexture        = new sf::Texture;
        pSprite         = new sf::Sprite;
        pBlackTexture   = new sf::Texture;
        pBlackSprite    = new sf::Sprite;

        *pPosition      = *other.pPosition;
        *pTexture       = *other.pTexture;
        *pSprite        = *other.pSprite;

        *pBlackTexture  = *other.pBlackTexture;
        *pBlackSprite   = *other.pBlackSprite;

        mMouseOnCard    = other.mMouseOnCard;
        mValue          = other.mValue;
        mHornochsen     = other.mHornochsen;
        mSpielerNr      = other.mSpielerNr;

        std::cout << "Assigned!\n";
    }

    return *this;
}

void card::update()
{
    if(mMouseOnCard && pSprite->getPosition().y > pPosition->y-30){
        pSprite->move(0,-1);
        pBlackSprite->move(0,-1);
    } else if (!mMouseOnCard && pSprite->getPosition().y < pPosition->y){
        pSprite->move(0,1);
        pBlackSprite->move(0,1);
    }
}

void card::handle(sf::Event *Event)
{
    if (Event->type == sf::Event::MouseMoved)
        {
            if(Event->mouseMove.x > pSprite->getPosition().x && Event->mouseMove.x < pSprite->getPosition().x+134
                && Event->mouseMove.y > pSprite->getPosition().y && Event->mouseMove.y < pPosition->y+204){
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
        if(CardValue%11 < 6){
            coordsy = 0;
            coordsx = (5 - CardValue%6)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-1)%5)*134;
        }
    } else if (CardValue < 21) {
        File = "Cards11-20";
        if((CardValue-10)%11 < 5){
            coordsy = 0;
            coordsx = (5 - (CardValue-10)%6)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-11)%5)*134;
        }
    } else if (CardValue < 31) {
        File = "Cards21-30";
        if((CardValue-20)%11 < 5){
            coordsy = 0;
            coordsx = (5 - (CardValue-20)%6)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-21)%5)*134;
        }
    } else if (CardValue < 41) {
        File = "Cards31-40";
        if((CardValue-30)%11 < 5){
            coordsy = 0;
            coordsx = (5 - (CardValue-30)%6)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-31)%5)*134;
        }
    } else if (CardValue < 51) {
        File = "Cards41-50";
        if((CardValue-40)%11 < 5){
            coordsy = 0;
            coordsx = (5 - (CardValue-40)%6)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-41)%5)*134;
        }
    } else if (CardValue < 61) {
        File = "Cards51-60";
        if((CardValue-50)%11 < 5){
            coordsy = 0;
            coordsx = (5 - (CardValue-50)%6)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-51)%5)*134;
        }
    } else if (CardValue < 71) {
        File = "Cards61-70";
        if((CardValue-60)%11 < 5){
            coordsy = 0;
            coordsx = (5 - (CardValue-60)%6)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-61)%5)*134;
        }
    } else if (CardValue < 81) {
        File = "Cards71-80";
        if((CardValue-70)%11 < 5){
            coordsy = 0;
            coordsx = (5 - (CardValue-70)%6)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-71)%5)*134;
        }
    } else if (CardValue < 91) {
        File = "Cards81-90";
        if((CardValue-80)%11 < 5){
            coordsy = 0;
            coordsx = (5 - (CardValue-80)%6)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-81)%5)*134;
        }
    } else if (CardValue < 101) {
        File = "Cards91-100";
        if((CardValue-90)%11 < 5){
            coordsy = 0;
            coordsx = (5 - (CardValue-90)%6)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-91)%5)*134;
        }
    } else if (CardValue < 105) {
        File = "Cards101-104";
        if((CardValue-100)%11 < 5){
            coordsy = 0;
            coordsx = (5 - (CardValue-100)%6)*134;
        } else {
            coordsy = 204;
            coordsx = (4 - (CardValue-101)%5)*134;
        }
    }

    std::stringstream ssfilename;
    ssfilename << Filedirectory << File << FileType;
    std::string filename = ssfilename.str();

    pTexture->loadFromFile(filename);
    pSprite->setTexture(*pTexture);

    pSprite->setTextureRect(sf::IntRect(coordsx,coordsy,134,204));
    pSprite->setPosition(sf::Vector2f(300, 200));
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
     pBlackSprite->setPosition(sf::Vector2f(pPosition->x - 10,pPosition->y - 10));
     pBlackSprite->setColor(sf::Color(255,255,255,150));
 }
