#include "AnimatedCard.hpp"

AnimatedCard::AnimatedCard(card &newCard, sf::Vector2f target)
    :mInAnimation(true),mTarget(target),mSpeed(3000)
{
    spAnimatedCard = std::shared_ptr<card>(new card);
    *spAnimatedCard = newCard;
//    spAnimatedCard->setPosition(target);

    CalculateMoveDirection(target);
}

AnimatedCard::~AnimatedCard()
{
    //dtor
}

void AnimatedCard::update()
{
    float FrameTime = FrameClock.restart().asSeconds();

    if(mInAnimation == false){                                      //set cards on target position if animation was ended
        spAnimatedCard->setPosition(mTarget);
    } else if(mTarget.x - spAnimatedCard->getPosition().x < 10){    // set cards on target position and end animation if difference is smaller than 10 pxls
        spAnimatedCard->setPosition(mTarget);
        mInAnimation = false;
    } else {                                                        //Move Card to new Position
        spAnimatedCard->setPosition(sf::Vector2f(spAnimatedCard->getPosition().x + mMoveDirection.x*mSpeed*FrameTime, spAnimatedCard->getPosition().y + mMoveDirection.y*mSpeed*FrameTime));
    }
}

void AnimatedCard::handle(sf::Event *event)
{

}

void AnimatedCard::render(sf::RenderWindow *rw)
{
    spAnimatedCard->render(rw);
}


///// SETTER /////
void AnimatedCard::setDirection(sf::Vector2f newDirection)
{
    mMoveDirection = newDirection;
}

void AnimatedCard::endAnimation()
{
    mInAnimation = false;
}

///// GETTER /////
bool AnimatedCard::getAnimationStatus()
{
    return mInAnimation;
}

void AnimatedCard::CalculateMoveDirection(sf::Vector2f target)
{
    sf::Vector2f    Direction;
    float           PathLength;

    Direction.x = target.x - spAnimatedCard->getPosition().x; //std::cout << "Directionvektor x: " << Target[i].x << std::endl;
    Direction.y = target.y - spAnimatedCard->getPosition().y; //std::cout << "Directionvektor y: " << Target[i].x << std::endl;

    PathLength = sqrt(Direction.x * Direction.x + Direction.y * Direction.y);

    this->mMoveDirection.x = Direction.x/PathLength;
    this->mMoveDirection.y = Direction.y/PathLength;
}
