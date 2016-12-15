#include "AnimatedCard.hpp"

AnimatedCard::AnimatedCard(card &newCard, sf::Vector2f target)
{
    spAnimatedCard = std::shared_ptr<card>(new card);
    *spAnimatedCard = newCard;
    spAnimatedCard->setPosition(target);
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
    spAnimatedCard->render(rw);
//    std::cout << "Here should be rendered!\n";
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

bool AnimatedCard::MoveCardToHold()
{
//    float CardW = 134.0, CardH = 205.0, WindowW = 1600.0;//, WindowH = 900.0;
//    float SpacingH = 0.8, SpacingW = 1.5;
//
//    sf::Vector2f    Target;
//    sf::Vector2f    Direction;
//    float           PathLength;
//    sf::Vector2f    DirectionUnit;
//
//    Direction.x = Target.x - ToPlay.getPosition().x; //std::cout << "Directionvektor x: " << Target[i].x << std::endl;
//    Direction.y = Target.y - ToPlay.getPosition().y; //std::cout << "Directionvektor y: " << Target[i].x << std::endl;
//
//    PathLength = sqrt(Direction[i].x * Direction[i].x + Direction[i].y * Direction[i].y);
//
//    DirectionUnit[i].x = Direction[i].x/PathLength[i]/10;
//    DirectionUnit[i].y = Direction[i].y/PathLength[i]/10;
//
//    ToPlay[i].setMoving(DirectionUnit[i],PathLength[i]);
//
//    if(Direction[0].x < 300 && Direction[0].y < 300 && Direction[0].x > -300 && Direction[0].y > -300){
//        return true; //Animation ended
//    } else {
        return false; //Animation didn't end yet!
//    }
}
