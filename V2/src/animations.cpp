#include "animations.hpp"

animations::animations()
{
    mAnimationFinished = false;
}

animations::~animations()
{

}

void animations::addCardWithTarget(card &newCard, sf::Vector2f target)
{
    upAnimatedCards.push_back(AnimatedCard(newCard, target));
}

void animations::addCardOnPosition(card &newCard, sf::Vector2f position)
{
    upAnimatedCards.push_back(AnimatedCard(newCard, position));
}

void animations::clearCards()
{
    upAnimatedCards.clear();
}

void animations::update()
{
    int NumberOfAnimationsNotFinished = 0;

    for(unsigned int i = 0; i<upAnimatedCards.size();i++)
    {
        upAnimatedCards[i].update();
        NumberOfAnimationsNotFinished += upAnimatedCards[i].getAnimationStatus();
    }

    if(NumberOfAnimationsNotFinished == 0){
        mAnimationFinished = true;
    } else {
        mAnimationFinished = false;
    }
}

void animations::handle(sf::Event *event)
{
    for(unsigned int i = 0; i<upAnimatedCards.size();i++)
    {
        upAnimatedCards[i].handle(event);

        if(upAnimatedCards[i].getAnimationStatus() && event->type == sf::Event::MouseButtonPressed && event->mouseButton.button == sf::Mouse::Left){
            upAnimatedCards[i].endAnimation();
//            std::cout << "Clicked!" << std::endl;
        }
    }
}

void animations::render(sf::RenderWindow *rw)
{
    for(auto it : upAnimatedCards){
        it.render(rw);
    }
}
