#include <LoadingScreen.hpp>
#include "Framework.hpp"

//std::shared_ptr<deck> LoadingScreen::spGameDeck;

LoadingScreen::LoadingScreen()
{
    LogoTexture = ResourceManager::getTexture("Resources\\Logo.png");//LogoTexture.loadFromFile("Resources\\Logo.png");
    LogoSprite.setTexture(LogoTexture);
    counter = 0;
}

LoadingScreen::~LoadingScreen()
{

}

void LoadingScreen::render(Framework &frmwrk)
{
    frmwrk.pRenderWindow->draw(LogoSprite);
    if(counter>0)
        init(frmwrk);
    counter++;
}

void LoadingScreen::init(Framework &frmwrk)
{
    spGameDeck = std::shared_ptr<deck>(new deck);
    // Deck will be shuffled on being requested (getDeckPTR)

    frmwrk.CurrentState = std::move(std::unique_ptr<MainMenu>(new MainMenu));
    std::cout << "Game loaded" << std::endl;
}
//
//static std::shared_ptr<deck> getDeckPTR()
//{
//    spGameDeck->mischen();
//    return spGameDeck;
//}
