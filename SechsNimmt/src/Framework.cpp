#include "Framework.hpp"

using namespace std;

Framework::Framework()
    :mGameRunning(false)
{
    pRenderWindow   = new sf::RenderWindow(sf::VideoMode(1600,800,32),"Sechs Nimmt!");
    pRenderWindow->setPosition(sf::Vector2i(0,0));
    pMainEvent      = new sf::Event;
    pClock          = new sf::Clock;
    mRun            = true;

    pBackground     = new sf::Texture;
    pBackground->loadFromFile("Resources\\Tisch_Hintergrund.png");
    pBackSprite     = new sf::Sprite;
    pBackSprite->setTexture(*pBackground);

//    NewGame(!mGameRunning);
    pButton         = new Button(sf::Vector2f(25,25),sf::Vector2f(200,50),"New Game");
}

Framework::~Framework(){
    delete pRenderWindow;
    delete pMainEvent;
    delete pClock;
    delete pBackground;
    delete pBackSprite;
    delete pButton;
//    delete pGM;
}

void Framework::NewGame(bool start)
{
    if(!start){
        delete pGM;
        pGM = NULL;
    }

    pGM         = new GameManager;
    mGameRunning = true;
}

void Framework::run(){

    while(mRun)
    {
        update(mFrameTime);
        handleEvents();
        render();

        quit();
    }
}

void Framework::quit(){
    if(mRun == false)
        pRenderWindow->close();
}

void Framework::update(float FrameTime)
{
    if(mGameRunning){
        pGM->update();
    }
    pButton->update();

    this->CalculateFrameTime();
}

void Framework::handleEvents()
{
    while(pRenderWindow->pollEvent(*pMainEvent))
    {
        if(pMainEvent->type == sf::Event::MouseButtonPressed && pMainEvent->mouseButton.button == sf::Mouse::Left){
            if(pButton->getMouseOnButton())
                NewGame(!mGameRunning);
        }

        if(mGameRunning){
            pGM->handle(pMainEvent);
        }

        pButton->handle(pMainEvent);

        if(pMainEvent->type == sf::Event::Closed)
            mRun = false;
    }
}

void Framework::render(){
    pRenderWindow->clear();

    pRenderWindow->draw(*pBackSprite);

    if(mGameRunning){
        pGM->render(pRenderWindow);
    }

    pButton->render(pRenderWindow);

    pRenderWindow->display();
}

void Framework::CalculateFrameTime()
{
    mFrameTime = pClock->getElapsedTime().asSeconds();
    pClock->restart();
//    cout << "FPS:" << 1/mFrameTime << endl;
}
