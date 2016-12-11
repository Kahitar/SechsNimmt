#ifndef ANIMATEDCARD_HPP
#define ANIMATEDCARD_HPP

#include <iostream>

#include "SFML/Graphics.hpp"
#include "card.hpp"

class AnimatedCard
{
    public:
        AnimatedCard();
        ~AnimatedCard();

        void setCard(card &newCard){};
        void setDirection(sf::Vector2f newDirection){};

        bool getAnimationStatus(){};

        void update(){};
        void handle(){};
        void render(){};

    private:
        std::unique_ptr<card> mAnimatedCard;

        bool mInAnimation;
        sf::Vector2f moveDirection;
};

#endif // ANIMATEDCARD_HPP
