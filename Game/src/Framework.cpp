#include "Framework.hpp"

using namespace std;

Framework::Framework(){
    MouseOnCard = false;

    pRenderWindow   = new sf::RenderWindow(sf::VideoMode(1600,900,32),"Little Game");
    pMainEvent      = new sf::Event;
    pClock          = new sf::Clock;
    mRun            = true;

    pBackground     = new sf::Texture;
    pBackground->loadFromFile("background.png");
    pBackSprite     = new sf::Sprite;
    pBackSprite->setTexture(*pBackground);

    pGM             = new GameManager;
}

Framework::~Framework(){

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

void Framework::update(float FrameTime){

    pGM->update();

    this->CalculateFrameTime();
}

void Framework::handleEvents()
{
    while(pRenderWindow->pollEvent(*pMainEvent))
    {


        pGM->handle(pMainEvent);

        if(pMainEvent->type == sf::Event::Closed)
            mRun = false;
    }
}

void Framework::render(){
    pRenderWindow->clear(sf::Color::Green);

    pGM->render(pRenderWindow);

    pRenderWindow->display();
}

void Framework::CalculateFrameTime()
{
    mFrameTime = pClock->getElapsedTime().asSeconds();
    pClock->restart();
//    cout << "FPS:" << 1/mFrameTime << endl;
}
