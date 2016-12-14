#include "animations.hpp"

animations::animations()
{
    //TODO: Initilize vector with the expected size (NumberOfKIs + 1)
    upAnimatedCards = std::move(std::unique_ptr<std::vector<AnimatedCard> > (new std::vector<AnimatedCard>));
}

animations::~animations()
{

}

void animations::addCard(card &newCard)
{
    upAnimatedCards->push_back(AnimatedCard(newCard));
    std::cout << "Now " << upAnimatedCards->size() << " Entries in the Animation Vector\n";
}

void animations::clearCards()
{
    upAnimatedCards->clear();
}

void animations::update()
{

}

void animations::handle(sf::Event *event)
{
    //TODO: Let Animation stop when clicked.
}

void animations::render(sf::RenderWindow *rw)
{
    for(auto it : *upAnimatedCards){
        it.render(rw);
    }
}
