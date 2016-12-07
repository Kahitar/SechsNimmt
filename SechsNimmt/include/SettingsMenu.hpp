#ifndef SETTINGSMENU_HPP
#define SETTINGSMENU_HPP

#include "Gamestate.hpp"
#include "Button.hpp"

class Framework;

class SettingsMenu : public Gamestate
{
    public:
         SettingsMenu();
        ~SettingsMenu();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    private:
        std::unique_ptr<Button> pNumberKIHeadline;
        std::unique_ptr<Button> pBackButton;
        std::unique_ptr<Button[]> pNumberKIButtons;
};

#endif // SETTINGSMENU_HPP
