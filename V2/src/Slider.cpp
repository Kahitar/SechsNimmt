#include "Slider.hpp"
#include "Framework.hpp"

Slider::Slider(sf::Vector2f pos, sf::Vector2f Size)
    :mMouseOnSlider(false),mClicked(false),mNumberOfPositions(1),mSliderValue(0)
{
//    upTexture   = std::move(std::unique_ptr<sf::Texture>(new sf::Texture));
//    upSprite    = std::move(std::unique_ptr<sf::Sprite>(new sf::Sprite));
    mSliderBar.setFillColor(sf::Color(128, 128, 128));
    mSliderRect.setFillColor(sf::Color::Blue);

    setSize(Size);
    setPosition(pos);
}

Slider::~Slider()
{
    //dtor
}

void Slider::update(Framework &frmwrk)
{
    if(mClicked){
        ChangeSliderPosition(sf::Mouse::getPosition(*frmwrk.pRenderWindow).x);
    }
}

void Slider::handle(sf::Event *event)
{
    if (event->type == sf::Event::MouseMoved)
    {
        if(event->mouseMove.x > mPos.x
            && event->mouseMove.y > mPos.y
            && event->mouseMove.x < mPos.x + mSize.x
            && event->mouseMove.y < mPos.y + mSize.y)
        {
            mMouseOnSlider = true;
        } else{
            mMouseOnSlider = false;
        }
    }
    if(event->type == sf::Event::MouseButtonReleased && mMouseOnSlider)
        mClicked = !mClicked;
    else if(event->type == sf::Event::MouseButtonReleased)
        mClicked = false;
}

void Slider::render(sf::RenderWindow *rw)
{
    rw->draw(mSliderBar);
    rw->draw(mSliderRect);
}

void Slider::ChangeSliderPosition(float MouseX)
{
    float newX;
    if(MouseX > mPos.x && MouseX < mPos.x + mSize.x - mBarWidth)
        newX = MouseX;
    else if (MouseX < mPos.x)
        newX = mPos.x;
    else
        newX = mPos.x + mSize.x - mBarWidth;
    mSliderRect.setPosition(sf::Vector2f(newX, mPos.y));
}

///////////Setter///////////
void Slider::setPosition(sf::Vector2f pos)
{
    mPos = pos;
    mSliderBar.setPosition(mPos.x, mPos.y + mSize.y/2 - mSize.y * 0.2 / 2);
    mSliderRect.setPosition(mPos);
}

void Slider::setSize(sf::Vector2f Size)
{
    mSize = Size;
    mBarWidth = mSize.x * 0.05;
    mSliderBar.setSize(sf::Vector2f(mSize.x, mSize.y * 0.2));
    mSliderRect.setSize(sf::Vector2f(mBarWidth, mSize.y));
}
