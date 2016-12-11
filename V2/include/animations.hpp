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

    private:
        std::vector<AnimatedCard> mvAnimatedObject;

};

#endif // ANIMATIONS_HPP
