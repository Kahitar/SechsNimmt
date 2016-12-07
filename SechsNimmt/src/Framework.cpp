#include "Framework.hpp"

#include "ResourceManager.hpp"

using namespace std;

Framework::Framework()
    :mGameRunning(false)
{
    pRenderWindow   = new sf::RenderWindow(sf::VideoMode(1600,800,32),"Sechs Nimmt!");
    pRenderWindow->setPosition(sf::Vector2i(2000,100));
    pMainEvent      = new sf::Event;
    pClock          = new sf::Clock;
    mRun            = true;

    pBackground     = new sf::Texture;
    *pBackground    = ResourceManager::getTexture("Resources\\Tisch_Hintergrund.png");//pBackground->loadFromFile("Resources\\Tisch_Hintergrund.png");
    pBackSprite     = new sf::Sprite;
    pBackSprite->setTexture(*pBackground);

    // Set Gamestate to GAMESTART, in case it is not changed in main
    CurrentState = std::move(std::unique_ptr<MainMenu>(new MainMenu));
//    pNewGameButton  = new Button(sf::Vector2f(25,25),sf::Vector2f(200,50),"New Game");
}

Framework::~Framework(){
    delete pRenderWindow;
    delete pMainEvent;
    delete pClock;
    delete pBackground;
    delete pBackSprite;
//    delete pNewGameButton;
//    if(mGameRunning){
//        delete pGM;
//        pGM = NULL;
//    }
}

//void Framework::NewGame()
//{
//    if(mGameRunning){
//        delete pGM;
//        pGM = NULL;
//    }
//
//    pGM          = new GameManager;
//    mGameRunning = true;
//}

void Framework::run(){

    while(mRun)
    {
        update(mFrameTime);
        handleEvents();
        render();

        quit();
    }
}

void Framework::ChangeState(gameStates newstate)
{
    switch(newstate)
    {
//    case gameStates::GAMESTART:
//        CurrentState = std::move(std::unique_ptr<LoadingScreen>(new LoadingScreen));
//    break;
    case gameStates::MAINMENU:
        CurrentState = std::move(std::unique_ptr<MainMenu>(new MainMenu));
    break;
    case gameStates::PLAY:
        CurrentState = std::move(std::unique_ptr<GameManager>(new GameManager));
    break;
    }
}

void Framework::quit(){
    if(mRun == false)
        pRenderWindow->close();
}

void Framework::update(float FrameTime)
{
    CurrentState->update(*this);
//    if(mGameRunning){
//        pGM->update(*this);
//    }
//    pNewGameButton->update();

    this->CalculateFrameTime();
}

void Framework::handleEvents()
{
    while(pRenderWindow->pollEvent(*pMainEvent))
    {
        CurrentState->handle(*this);
        if(pMainEvent->type == sf::Event::MouseButtonPressed && pMainEvent->mouseButton.button == sf::Mouse::Left){
//            if(pNewGameButton->getMouseOnButton())
//                NewGame();
        }

//        if(mGameRunning){
//            pGM->handle(*this);
//        }

//        pNewGameButton->handle(*this);

        if(pMainEvent->type == sf::Event::Closed)
            mRun = false;
    }
}

void Framework::render(){
    pRenderWindow->clear();

    pRenderWindow->draw(*pBackSprite);

    CurrentState->render(*this);
//    if(mGameRunning){
//        pGM->render(*this);
//    }

//    pNewGameButton->render(pRenderWindow);

    pRenderWindow->display();
}

void Framework::CalculateFrameTime()
{
    mFrameTime = pClock->getElapsedTime().asSeconds();
    pClock->restart();
//    cout << "FPS:" << 1/mFrameTime << endl;
}
