#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Gamestate.hpp"
#include "Button.hpp"

class Framework;

class MainMenu : public Gamestate
{
public:
     MainMenu();
    ~MainMenu();

    void update(Framework &frmwrk);
    void handle(Framework &frmwrk);
    void render(Framework &frmwrk);

private:
    std::unique_ptr<Button> pNewGameButton;
    std::unique_ptr<Button> pSettings;
    std::unique_ptr<Button> pExitButton;
};

#endif // MAINMENU_HPP
