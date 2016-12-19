#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Gamestate.hpp"
#include "Button.hpp"
#include "Slider.hpp"

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
    std::unique_ptr<Button> pSettingsButton;
    std::unique_ptr<Button> pExitButton;

    std::unique_ptr<Slider> upSlider;
};

#endif // MAINMENU_HPP
