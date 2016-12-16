#include "animations.hpp"

animations::animations()
{
    //TODO: Initilize vector with the expected size (NumberOfKIs + 1)
    upAnimatedCards = std::move(std::unique_ptr<std::vector<AnimatedCard> > (new std::vector<AnimatedCard>));

    mAnimationFinished = false;
}

animations::~animations()
{

}

void animations::addCard(card &newCard, sf::Vector2f target)
{
    upAnimatedCards->push_back(AnimatedCard(newCard, target));
}

void animations::clearCards()
{
    upAnimatedCards->clear();
}

void animations::update()
{
    int NumberOfAnimationsNotFinished = 0;
    for(auto it : *upAnimatedCards){
        it.update();
        NumberOfAnimationsNotFinished += it.getAnimationStatus();
    }
    if(NumberOfAnimationsNotFinished == 0){
        mAnimationFinished = true;
    } else {
        mAnimationFinished = false;
    }
}

void animations::handle(sf::Event *event)
{
    for(auto it : *upAnimatedCards){
        it.handle(event);

        if(it.getAnimationStatus() && event->type == sf::Event::MouseButtonPressed && event->mouseButton.button == sf::Mouse::Left){
            it.endAnimation();
            std::cout << "Clicked!" << std::endl;
        }
    }
    //TODO: Let Animation stop when clicked.
}

void animations::render(sf::RenderWindow *rw)
{
    for(auto it : *upAnimatedCards){
        it.render(rw);
    }
}
