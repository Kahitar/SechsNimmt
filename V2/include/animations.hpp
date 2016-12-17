#ifndef ANIMATIONS_HPP
#define ANIMATIONS_HPP

#include <iostream>
#include <map>

#include "AnimatedCard.hpp"

class animations
{
    public:
        animations();
        ~animations();

        void addCard(card &newCard, sf::Vector2f target);
        void clearCards();

        void update();
        void handle(sf::Event *event);
        void render(sf::RenderWindow *rw);

        ///// GETTER /////
        bool isAnimationFinished() {return mAnimationFinished;};

    private:
        std::vector<AnimatedCard> upAnimatedCards;

        bool mAnimationFinished;
};

#endif // ANIMATIONS_HPP
