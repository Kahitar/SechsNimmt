#include "SettingsMenu.hpp"
#include "Framework.hpp"
#include "ResourceManager.hpp"
#include <string>

SettingsMenu::SettingsMenu()
{
    pNumberKIHeadline   = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(550,300),sf::Vector2f(500,50),"Number of KIs")));
    pBackButton         = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(700,500),sf::Vector2f(200,50),"Back")));
    pNumberKIButtons    = std::move(std::unique_ptr<Button[]>(new Button[10]));

    for(int i = 0;i<10;i++){
        pNumberKIButtons[i].setPosition(sf::Vector2f(550+i*50,360));
        pNumberKIButtons[i].setSize(sf::Vector2f(45,50));
    }
    pNumberKIButtons[0].setText("0");pNumberKIButtons[1].setText("1");pNumberKIButtons[2].setText("2");pNumberKIButtons[3].setText("3");pNumberKIButtons[4].setText("4");
    pNumberKIButtons[5].setText("5");pNumberKIButtons[6].setText("6");pNumberKIButtons[7].setText("7");pNumberKIButtons[8].setText("8");pNumberKIButtons[9].setText("9");
}

SettingsMenu::~SettingsMenu()
{
    //dtor
}

void SettingsMenu::update(Framework &frmwrk)
{
    pBackButton->update();

    for(int i = 0;i<10;i++){
        if(ResourceManager::getKINumber() == i){
            pNumberKIButtons[i].setColor(sf::Color::Green);
        } else {
            pNumberKIButtons[i].setColor(sf::Color::White);
        }
        pNumberKIButtons[i].update();
    }
}

void SettingsMenu::handle(Framework &frmwrk)
{
    pBackButton->handle(frmwrk.pMainEvent);

    for(int i = 0;i<10;i++){
        pNumberKIButtons[i].handle(frmwrk.pMainEvent);
    }

    if(frmwrk.pMainEvent->type == sf::Event::MouseButtonPressed
       && frmwrk.pMainEvent->mouseButton.button == sf::Mouse::Left)
    {
        for(int i = 0;i<10;i++){
            if(pNumberKIButtons[i].getMouseOnButton()){
                ResourceManager::setKINumber(i);
            }
        }
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

    for(int i = 0;i<10;i++){
        pNumberKIButtons[i].render(frmwrk.pRenderWindow);
    }
}
