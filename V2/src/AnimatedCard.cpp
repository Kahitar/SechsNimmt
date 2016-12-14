#include "AnimatedCard.hpp"

AnimatedCard::AnimatedCard(card &newCard)
{
    upAnimatedCard = std::shared_ptr<card>(new card);
    *upAnimatedCard = newCard;
}

AnimatedCard::~AnimatedCard()
{
    //dtor
}

void AnimatedCard::update()
{

}

void AnimatedCard::handle(sf::Event *event)
{

}

void AnimatedCard::render(sf::RenderWindow *rw)
{
    std::cout << "Here should be rendered!\n";
}


///// SETTER /////
void AnimatedCard::setDirection(sf::Vector2f newDirection)
{
    mMoveDirection = newDirection;
}

///// GETTER /////
bool AnimatedCard::getAnimationStatus()
{
    return mInAnimation;
}


