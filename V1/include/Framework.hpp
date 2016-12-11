#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include <SFML\Graphics.hpp>

#include "card.hpp"
#include "Spieler.hpp"
#include "Reihen.hpp"
#include "GameManager.hpp"

class Framework
{
public:
     Framework();
    ~Framework();

    void run();

private:
    void quit();
    void update(float mFrameTime);
    void handleEvents();
    void render();

    void CalculateFrameTime();
    void CalculateScale();

    sf::RenderWindow *pRenderWindow;
    sf::Event        *pMainEvent;
    sf::Clock        *pClock;

    sf::Texture      *pBackground;
    sf::Sprite       *pBackSprite;

    float   mFrameTime;
    bool    mRun;

    bool    MouseOnCard;

    GameManager *pGM;
};

#endif // FRAMEWORK_HPP
