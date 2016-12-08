#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class Button
{
    public:
        Button(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f Size = sf::Vector2f(200, 50), std::string text = "Button");
        ~Button();

        void update();
        void handle(sf::Event *event);
        void render(sf::RenderWindow *rw);

        ///////////Setter///////////
        void setText(std::string text);
        void setPosition(sf::Vector2f pos);
        void setSize(sf::Vector2f Size);
        void setColor(sf::Color color);

        ///////////Getter///////////
        sf::Vector2f getPosition()          {return *pPos;};
        sf::Vector2f getSize()              {return *pSize;};

        bool getMouseOnButton()             {return mMouseOnButton;};

    protected:

    private:
        sf::Text        *pText;
        sf::Font        *pFont;

        sf::Vector2f    *pPos;
        sf::Vector2f    *pSize;

        sf::Texture     *pTexture;
        sf::Sprite      *pSpriteNotHovered;
        sf::Sprite      *pSpriteHovered;

        float           TextureHeight;
        float           TextureWidth;

        bool            mMouseOnButton;
        bool            mClicked;
};

#endif // BUTTON_HPP
