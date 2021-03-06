#ifndef ANIMATEDCARD_HPP
#define ANIMATEDCARD_HPP

#include <iostream>

#include "SFML/Graphics.hpp"
#include "card.hpp"

class AnimatedCard
{
    public:
        AnimatedCard() {};
        AnimatedCard(card &newCard, sf::Vector2f target);
        ~AnimatedCard();

        ///// SETTER /////
        void setDirection(sf::Vector2f newDirection);
        void endAnimation();

        ///// GETTER /////
        bool getAnimationStatus();


        void CalculateMoveDirection(sf::Vector2f target);
        void update();
        void handle(sf::Event *event);
        void render(sf::RenderWindow *rw);

    private:
        std::shared_ptr<card> spAnimatedCard;

//        std::string mAnimationType; // hold = move to the right after played; append = append to a row after hold;

        bool mInAnimation;
        sf::Vector2f mMoveDirection;
        sf::Vector2f mTarget;
        float mSpeed;
        sf::Clock FrameClock;
};

#endif // ANIMATEDCARD_HPP
