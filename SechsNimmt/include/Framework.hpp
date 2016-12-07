#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include <SFML\Graphics.hpp>

#include "Gamestate.hpp"
#include "MainMenu.hpp"
#include "GameManager.hpp"

class Framework
{
public:
     Framework();
    ~Framework();

    enum class gameStates {GAMESTART, MAINMENU, PLAY};

    void run();
    void ChangeState(gameStates newstate);

    sf::RenderWindow *pRenderWindow;
    sf::Event        *pMainEvent;

    //TODO: Make private (see error in MainMenu.handle())
    std::unique_ptr<Gamestate> CurrentState;

private:
    void quit();
    void update(float mFrameTime);
    void handleEvents();
    void render();

    void CalculateFrameTime();
    void CalculateScale();

    sf::Clock        *pClock;

    sf::Texture      *pBackground;
    sf::Sprite       *pBackSprite;

    float   mFrameTime;
    bool    mRun;

    bool    mGameRunning;
};

#endif // FRAMEWORK_HPP
