#include "Slider.hpp"
#include "Framework.hpp"

#include <string>

Slider::Slider(sf::Vector2f pos, sf::Vector2f Size)
    :mMouseOnSlider(false),mClicked(false),mNumberOfPositions(10),mSliderValue(0)
{
//    upTexture   = std::move(std::unique_ptr<sf::Texture>(new sf::Texture));
//    upSprite    = std::move(std::unique_ptr<sf::Sprite>(new sf::Sprite));

    mSliderBar.setFillColor(sf::Color(128, 128, 200));
    mSliderBar.setOutlineThickness(1);
    mSliderBar.setOutlineColor(sf::Color::Black);

    mSliderRect.setFillColor(sf::Color::Blue);
    mSliderRect.setOutlineThickness(1);
    mSliderRect.setOutlineColor(sf::Color::Black);

    setSize(Size);
    setPosition(pos);
    setValue(3);
}

Slider::~Slider()
{
    //dtor
}

void Slider::update(Framework &frmwrk)
{
    sf::RenderWindow *window = frmwrk.pRenderWindow;

    // get the current mouse position in the window
    sf::Vector2i MousePixelPos = sf::Mouse::getPosition(*window);
    // convert it to world coordinates
    sf::Vector2f MouseWorldPos = window->mapPixelToCoords(MousePixelPos);

    if(mClicked){
        ChangeSliderPosition(MouseWorldPos.x);
    }
}

void Slider::handle(Framework &frmwrk)
{
    sf::Event *event = frmwrk.pMainEvent;
    sf::RenderWindow *window = frmwrk.pRenderWindow;

    // get the current mouse position in the window
    sf::Vector2i MousePixelPos = sf::Mouse::getPosition(*window);
    // convert it to world coordinates
    sf::Vector2f MouseWorldPos = window->mapPixelToCoords(MousePixelPos);

    if(MouseWorldPos.x > mPos.x
        && MouseWorldPos.y > mPos.y
        && MouseWorldPos.x < mPos.x + mSize.x
        && MouseWorldPos.y < mPos.y + mSize.y)
    {
        mMouseOnSlider = true;
    } else{
        mMouseOnSlider = false;
    }

    if(event->type == sf::Event::MouseButtonPressed && mMouseOnSlider)
        mClicked = true;
    else if(event->type == sf::Event::MouseButtonReleased)
        mClicked = false;
}

void Slider::render(sf::RenderWindow *rw)
{
    rw->draw(mSliderBar);
    rw->draw(mSliderRect);

    sf::Text SliderValueText;
    sf::Font Font;

    Font.loadFromFile("Resources\\PAPYRUS.TTF");
    SliderValueText.setFont(Font);
    SliderValueText.setFillColor(sf::Color::Black);
    SliderValueText.setStyle(sf::Text::Bold);

    std::stringstream ssSliderValue;
    ssSliderValue << mSliderValue;
    std::string sSliderValue = ssSliderValue.str();

    SliderValueText.setString(sSliderValue);
    SliderValueText.setPosition(mPos.x - SliderValueText.getGlobalBounds().width - 10, mPos.y);
    rw->draw(SliderValueText);
}

void Slider::ChangeSliderPosition(float MouseX)
{
    float left = 0;
    float right = 1;
    float newX = 0;

    float PosWidth = (mSize.x - mBarWidth) / (mNumberOfPositions - 1);

    for(int i = 0; i < mNumberOfPositions; i++){
        left = mPos.x + i*PosWidth;
        right = mPos.x + (i+1)*PosWidth;

        if(MouseX >= left && MouseX < right) {
            newX = left;
            mSliderValue = i;
        }
        else if (MouseX < mPos.x){
            newX = mPos.x;
            mSliderValue = 0;
        }
        else if (MouseX > mPos.x + mSize.x - mBarWidth){
            newX = mPos.x + mSize.x - mBarWidth;
            mSliderValue = mNumberOfPositions-1;
        }
    }

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

void Slider::setValue(int newValue)
{
    float PosWidth = mSize.x / (mNumberOfPositions-1);
    float left = mPos.x + newValue*PosWidth;
    float right = mPos.x + (newValue+1)*PosWidth;
    float middle = (right + left - mBarWidth) / 2;

    float newX = middle -  mBarWidth/2;
    mSliderValue = newValue;
    mSliderRect.setPosition(sf::Vector2f(newX, mPos.y));
}

void Slider::setNumberOfPositions(int newNumber)
{
    mNumberOfPositions = newNumber;
}
