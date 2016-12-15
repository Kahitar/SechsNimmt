#include "constants.hpp"
#include "Framework.hpp"
#include "ResourceManager.hpp"
using namespace std;

Framework::Framework()
{
    pRenderWindow   = new sf::RenderWindow(sf::VideoMode(constants::WindowW,constants::WindowH,32),"Sechs Nimmt!");
    pRenderWindow->setPosition(sf::Vector2i(50,50));
    pMainEvent      = new sf::Event;
    pClock          = new sf::Clock;
    mRunning        = true;

    pBackground     = new sf::Texture;
    *pBackground    = ResourceManager::getTexture("Resources\\Tisch_Hintergrund.png");//pBackground->loadFromFile("Resources\\Tisch_Hintergrund.png");
    pBackSprite     = new sf::Sprite;
    pBackSprite->setTexture(*pBackground);

    // Set Gamestate to MAINMENU, in case it is not changed in main
    CurrentState = std::move(std::unique_ptr<MainMenu>(new MainMenu));
}

Framework::~Framework()
{
    delete pRenderWindow;
    delete pMainEvent;
    delete pClock;
    delete pBackground;
    delete pBackSprite;
}

void Framework::run()
{

    while(mRunning)
    {
        update(mFrameTime);
        handleEvents();
        render();

        if(mRunning == false)
            quit();
    }
}

void Framework::ChangeState(gameStates newstate)
{
    switch(newstate)
    {
    case gameStates::MAINMENU:
        CurrentState = std::move(std::unique_ptr<MainMenu>(new MainMenu));
    break;
    case gameStates::SETTINGS:
        CurrentState = std::move(std::unique_ptr<SettingsMenu>(new SettingsMenu));
    break;
    case gameStates::PLAY:
        CurrentState = std::move(std::unique_ptr<GameManager>(new GameManager(ResourceManager::getKINumber())));
    break;
    }
}

void Framework::quit()
{
    pRenderWindow->close();
    mRunning = false;
}

void Framework::update(float FrameTime)
{
    CurrentState->update(*this);

    this->CalculateFrameTime();
}

void Framework::handleEvents()
{
    while(pRenderWindow->pollEvent(*pMainEvent))
    {
        CurrentState->handle(*this);

        if(pMainEvent->type == sf::Event::MouseButtonPressed){
            if(pMainEvent->mouseButton.button == sf::Mouse::Left){

            }
        }
        if(pMainEvent->type == sf::Event::Closed)
            mRunning = false;
    }
}

void Framework::render()
{
    pRenderWindow->clear();

    pRenderWindow->draw(*pBackSprite);

    CurrentState->render(*this);

    pRenderWindow->display();
}

void Framework::CalculateFrameTime()
{
    mFrameTime = pClock->getElapsedTime().asSeconds();
    pClock->restart();
//    cout << "FPS:" << 1/mFrameTime << endl;
}
