#include "Button.hpp"
#include "Framework.hpp"

Button::Button(sf::Vector2f pos, sf::Vector2f Size, std::string text)
    :mMouseOnButton(false),mClicked(false)
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

    pSpriteHovered->setTexture(*pTexture);
    pSpriteHovered->setTextureRect(sf::IntRect(0, 0, TextureWidth, TextureHeight));
    pSpriteNotHovered->setTexture(*pTexture);
    pSpriteNotHovered->setTextureRect(sf::IntRect(0, TextureHeight, TextureWidth, TextureHeight));

    pSpriteHovered->setPosition(pos);
    pSpriteNotHovered->setPosition(pos);

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
    pText->setPosition(pPos->x + pSpriteNotHovered->getGlobalBounds().width/2, pPos->y + pSpriteNotHovered->getGlobalBounds().height/2);
}

void Button::setSize(sf::Vector2f Size)
{
    *pSize = Size;

    float scaleX = Size.x / TextureWidth;
    float scaleY = Size.y / TextureHeight;

    pSpriteNotHovered->setScale(scaleX, scaleY);
    pSpriteHovered->setScale(scaleX, scaleY);

    pText->setCharacterSize(Size.y*0.5);

    //TODO: x-Position for the KI-Number-Select-Buttons is wrong, why? This seems to have something to do with calling setPos() after the constructor
    pText->setPosition(pPos->x + pSpriteNotHovered->getGlobalBounds().width*1.4, pPos->y + pSpriteNotHovered->getGlobalBounds().height/2);
}

void Button::setColor(sf::Color color)
{
    pSpriteHovered->setColor(color);
    pSpriteNotHovered->setColor(color);
}

void Button::update()
{

}

void Button::handle(Framework &frmwrk)
{
    sf::Event *event = frmwrk.pMainEvent;
    sf::RenderWindow *window = frmwrk.pRenderWindow;

    // get the current mouse position in the window
    sf::Vector2i MousePixelPos = sf::Mouse::getPosition(*window);
    // convert it to world coordinates
    sf::Vector2f MouseWorldPos = window->mapPixelToCoords(MousePixelPos);

    if(MouseWorldPos.x > pPos->x
        && MouseWorldPos.y > pPos->y
        && MouseWorldPos.x < pPos->x + pSize->x
        && MouseWorldPos.y < pPos->y + pSize->y)
        mMouseOnButton = true;
    else
        mMouseOnButton = false;

    if(event->type == sf::Event::MouseButtonReleased && mMouseOnButton)
        mClicked = !mClicked;
}

void Button::render(sf::RenderWindow *rw)
{
    if(mMouseOnButton){
        rw->draw(*pSpriteHovered);
    } else {
        rw->draw(*pSpriteNotHovered);
    }
    rw->draw(*pText);
}
