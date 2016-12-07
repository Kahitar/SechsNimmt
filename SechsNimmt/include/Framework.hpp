#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include <SFML\Graphics.hpp>

#include "Gamestate.hpp"
#include "MainMenu.hpp"
#include "SettingsMenu.hpp"
#include "GameManager.hpp"

class Framework
{
public:
     Framework();
    ~Framework();

    enum class gameStates {SETTINGS, MAINMENU, PLAY};

    void run();
    void quit();
    void ChangeState(gameStates newstate);

    sf::RenderWindow *pRenderWindow;
    sf::Event        *pMainEvent;

private:
    void update(float mFrameTime);
    void handleEvents();
    void render();

    void CalculateFrameTime();
    void CalculateScale();

    std::unique_ptr<Gamestate> CurrentState;

    sf::Clock        *pClock;

    sf::Texture      *pBackground;
    sf::Sprite       *pBackSprite;

    float   mFrameTime;
    bool    mRunning;
};

#endif // FRAMEWORK_HPP
