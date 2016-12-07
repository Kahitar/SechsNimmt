#include "MainMenu.hpp"
#include "Framework.hpp"


MainMenu::MainMenu()
{
    pNewGameButton = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(700,300),sf::Vector2f(200,50),"New Game")));
    pSettings = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(700,400),sf::Vector2f(200,50),"Settings")));
    pExitButton = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(700,500),sf::Vector2f(200,50),"Exit Game")));
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(Framework &frmwrk)
{
    pNewGameButton->update();
    pSettings->update();
    pExitButton->update();
}

void MainMenu::handle(Framework &frmwrk)
{
    pNewGameButton->handle(frmwrk.pMainEvent);
    pSettings->handle(frmwrk.pMainEvent);
    pExitButton->handle(frmwrk.pMainEvent);

    if(frmwrk.pMainEvent->type == sf::Event::MouseButtonPressed && frmwrk.pMainEvent->mouseButton.button == sf::Mouse::Left){
        if(pNewGameButton->getMouseOnButton()){
            //TODO: solve error ("frmwrk is not a class,..."), make Framework::CurrentState() private
//            frmwrk.ChangeState(frmwrk::gameStates::PLAY);
            frmwrk.CurrentState = std::move(std::unique_ptr<GameManager>(new GameManager));
        }
    }
}

void MainMenu::render(Framework &frmwrk)
{
    pNewGameButton->render(frmwrk.pRenderWindow);
    pSettings->render(frmwrk.pRenderWindow);
    pExitButton->render(frmwrk.pRenderWindow);
}
