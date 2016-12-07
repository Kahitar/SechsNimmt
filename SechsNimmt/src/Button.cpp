#include "Button.hpp"

Button::Button(sf::Vector2f pos, sf::Vector2f Size, std::string text = "Button")
    :mMouseOnButton(false)
{
    pFont               = new sf::Font;
    pText               = new sf::Text;

    this->setText(text);

    pFont->loadFromFile("Resources\\PAPYRUS.TTF");
    pText->setFont(*pFont);
    pText->setFillColor(sf::Color::Black);
    pText->setStyle(sf::Text::Bold);

    pTexture            = new sf::Texture;
    pSpriteNotHovered   = new sf::Sprite;
    pSpriteHovered      = new sf::Sprite;

    sf::Image subImage;
    subImage.loadFromFile("Resources\\Button.png");
    subImage.createMaskFromColor(sf::Color::White);

    pTexture->loadFromImage(subImage);
    TextureHeight = 50.0;
    TextureWidth = 200.0;

    pSpriteNotHovered->setTexture(*pTexture);
    pSpriteNotHovered->setTextureRect(sf::IntRect(0, 0, TextureWidth, TextureHeight));
    pSpriteHovered->setTexture(*pTexture);
    pSpriteHovered->setTextureRect(sf::IntRect(0, TextureHeight, TextureWidth, TextureHeight));

    pSpriteNotHovered->setPosition(pos);
    pSpriteHovered->setPosition(pos);

    pPos                = new sf::Vector2f;
    pSize               = new sf::Vector2f;
    setSize(Size);
    setPosition(pos);
}

Button::~Button()
{
    delete pFont;
    pFont = NULL;
    delete pText;
    pText = NULL;
    delete pPos;
    pPos = NULL;
    delete pSize;
    pSize = NULL;
    delete pTexture;
    pTexture = NULL;
    delete pSpriteNotHovered;
    pSpriteNotHovered = NULL;
    delete pSpriteHovered;
    pSpriteHovered = NULL;
}

void Button::setText(std::string text)
{
    pText->setString(text);
}

void Button::setPosition(sf::Vector2f pos)
{
    *pPos = pos;

    pSpriteNotHovered->setPosition(pos);
    pSpriteHovered->setPosition(pos);

    pText->setOrigin(pText->getGlobalBounds().width/2, pText->getGlobalBounds().height/2);
    pText->setPosition(pos.x + pSpriteNotHovered->getGlobalBounds().width/2, pos.y + pSpriteNotHovered->getGlobalBounds().height/2);
}

void Button::setSize(sf::Vector2f Size)
{
    *pSize = Size;

    float scaleX = Size.x / TextureWidth;
    float scaleY = Size.y / TextureHeight;

    pSpriteNotHovered->setScale(scaleX, scaleY);
    pSpriteHovered->setScale(scaleX, scaleY);

    pText->setCharacterSize(Size.y*0.5);
}

void Button::update()
{

}

void Button::handle(sf::Event *event)
{
    if (event->type == sf::Event::MouseMoved)
        {
            if(event->mouseMove.x > pPos->x && event->mouseMove.x < pPos->x + pSize->x
                && event->mouseMove.y > pPos->y && event->mouseMove.y < pPos->y + pSize->y){
                mMouseOnButton = true;
            } else{
                mMouseOnButton = false;
            }
        }
}

void Button::render(sf::RenderWindow *rw)
{
    if(mMouseOnButton){
        rw->draw(*pSpriteNotHovered);
    } else {
        rw->draw(*pSpriteHovered);
    }
    rw->draw(*pText);
}

