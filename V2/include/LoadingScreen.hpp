#ifndef LOADINGSCREEN_HPP
#define LOADINGSCREEN_HPP

#include <SFML/Graphics.hpp>

#include "Gamestate.hpp"

class Framework;

class LoadingScreen : public Gamestate
{
public:
     LoadingScreen();
    ~LoadingScreen();

    void init(Framework &frmwrk);
    void update(Framework &frmwrk) {};
    void handle(Framework &frmwrk) {};
    void render(Framework &frmwrk);

//    static std::shared_ptr<deck> getDeckPTR();

private:
    sf::Texture LogoTexture;
    sf::Sprite  LogoSprite;

//    static std::shared_ptr<deck> spGameDeck;

    int counter;
};



#endif // LOADINGSCREEN_HPP
