#include "SettingsMenu.hpp"
#include "Framework.hpp"
#include "ResourceManager.hpp"
#include <string>

SettingsMenu::SettingsMenu()
{
    pNumberKIHeadline   = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(500,300),sf::Vector2f(200,50),"Number of KIs:")));
    upKISlider          = std::move(std::unique_ptr<Slider>(new Slider(sf::Vector2f(750,300),sf::Vector2f(200,50))));
    pBackButton         = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(700,500),sf::Vector2f(200,50),"Back")));

    upKISlider->setValue(ResourceManager::getKINumber());
}

SettingsMenu::~SettingsMenu()
{
    //dtor
}

void SettingsMenu::update(Framework &frmwrk)
{
    pBackButton->update();
    upKISlider->update(frmwrk);
    ResourceManager::setKINumber(upKISlider->getSliderValue());
}

void SettingsMenu::handle(Framework &frmwrk)
{
    pBackButton->handle(frmwrk.pMainEvent);
    upKISlider->handle(frmwrk.pMainEvent);

    if(frmwrk.pMainEvent->type == sf::Event::MouseButtonPressed
       && frmwrk.pMainEvent->mouseButton.button == sf::Mouse::Left)
    {
        //Change Game State must always be the lastone, otherwise buttons get deleted and I'm getting segfaults (?!)
        if (pBackButton->getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::MAINMENU);
        }
    }
}

void SettingsMenu::render(Framework &frmwrk)
{
    pNumberKIHeadline->render(frmwrk.pRenderWindow);
    pBackButton->render(frmwrk.pRenderWindow);
    upKISlider->render(frmwrk.pRenderWindow);
}
