#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include <SFML\Graphics.hpp>

#include "card.hpp"
#include "Spieler.hpp"
#include "Reihen.hpp"
#include "GameManager.hpp"
#include "Button.hpp"

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

    void NewGame();

    void CalculateFrameTime();
    void CalculateScale();

    sf::RenderWindow *pRenderWindow;
    sf::Event        *pMainEvent;
    sf::Clock        *pClock;

    sf::Texture      *pBackground;
    sf::Sprite       *pBackSprite;

    float   mFrameTime;
    bool    mRun;

    bool    mGameRunning;

    GameManager *pGM;
    Button      *pNewGameButton;
};

#endif // FRAMEWORK_HPP
