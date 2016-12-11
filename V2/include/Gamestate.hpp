#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <iostream>
#include <memory>

class Framework;

class Gamestate
{
public:
    virtual void update(Framework &frmwrk) = 0;
    virtual void handle(Framework &frmwrk) = 0;
    virtual void render(Framework &frmwrk) = 0;
    virtual     ~Gamestate() {};
};

#endif // GAMESTATE_HPP
