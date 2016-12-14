#ifndef ANIMATEDCARD_HPP
#define ANIMATEDCARD_HPP

#include <iostream>

#include "SFML/Graphics.hpp"
#include "card.hpp"

class AnimatedCard
{
    public:
        AnimatedCard() {};
        AnimatedCard(card &newCard);
        ~AnimatedCard();

        ///// SETTER /////
        void setDirection(sf::Vector2f newDirection);

        ///// GETTER /////
        bool getAnimationStatus();



        void update();
        void handle(sf::Event *event);
        void render(sf::RenderWindow *rw);

    private:
        std::shared_ptr<card> upAnimatedCard;

        std::string mAnimationType; // hold = move to the right after played; append = append to a row after hold;

        bool mInAnimation;
        sf::Vector2f mMoveDirection;
};

#endif // ANIMATEDCARD_HPP
