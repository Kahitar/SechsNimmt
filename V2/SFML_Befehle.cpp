#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

//Windowsmodul
void openWindow(){
    int scale = 300;
    sf::RenderWindow window(sf::VideoMode(scale,scale), "SFML works!");
    window.setPosition(sf::Vector2i(1650-scale,50));
    window.setVerticalSyncEnabled(true);

    sf::CircleShape shape(scale/2);
    shape.setFillColor(sf::Color::Red);

    // Main-/Gameloop
    while (window.isOpen()){
        sf::Event event;
        //Eventloop
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //Keyboard Key
            if (event.type == sf::Event::KeyPressed)
            {
                //Einzelne Taste:
                if(event.key.code == sf::Keyboard::A)
                {
                    cout << "A pressed"<<endl;
                }

                //Oder alternativ:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    cout << "Escape pressed" << endl;
                }

                if (event.key.code == sf::Keyboard::H)
                {
                    std::cout << "the H key was pressed" << std::endl;
                    std::cout << "control: " << event.key.control << std::endl;
                    std::cout << "alt: " << event.key.alt << std::endl;
                    std::cout << "shift: " << event.key.shift << std::endl;
                    std::cout << "system: " << event.key.system << std::endl;
                }
            }

            //Scroll Wheel
            if (event.type == sf::Event::MouseWheelScrolled)
            {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                    std::cout << "wheel type: vertical" << std::endl;
                else
                    std::cout << "wheel type:   unknown" << std::endl;
                std::cout << "clicks moved: " << event.mouseWheelScroll.delta << std::endl;
                std::cout << "mouse x:      " << event.mouseWheelScroll.x << std::endl;
                std::cout << "mouse y:      " << event.mouseWheelScroll.y << std::endl;
            }

            //Mousebutton
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }

                if (event.mouseButton.button == sf::Mouse::Middle)
                {
                    std::cout << "the middle button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
            }

            //Mouse moves
            if (event.type == sf::Event::MouseMoved)
            {
                std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
                std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
            }

            //Mouse enters and leaves
            if (event.type == sf::Event::MouseEntered)
                std::cout << "the mouse cursor has entered the window" << std::endl;

            if (event.type == sf::Event::MouseLeft)
                std::cout << "the mouse cursor has left the window" << std::endl;

        }

        //Mouseposition
        sf::Vector2i globalPosition = sf::Mouse::getPosition(/*optional: window*/);
        //sf::Mouse::setPosition(sf::Vector2i(10, 50), window);

        window.clear();
        window.draw(shape);
        window.display();
    }
}

//Graphikmodul
void drawGraphics(){

    // Daten
    float WindowHeight = 900;
    float WindowWidth = 1200;

    float CardHeight = 1022;
    float CardWidth = 664;

    float CardScale = (WindowWidth/CardWidth*8.0)/93;
    float CardHeightScaled = CardHeight*CardScale;
    float CardWidthScaled = CardWidth*CardScale;

    float CardDistance = 0.75 * CardWidth * CardScale;

    cout << CardScale;

    // create the window
    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "6 nimmt !");

    //Load Texture
    sf::Texture karten1bis10;
    if(!karten1bis10.loadFromFile("Karten_1-10.jpg"))
        cout << "Error loading a file!";

    //Create Sprite and set texture
    sf::Sprite spKarten1bis10[5][2];
    for(int i = 0;i<5;i++){
        for(int j = 0;j<2;j++){
            spKarten1bis10[i][j].setTexture(karten1bis10);
        }

    }

    //Manipulate Sprite
    for(int j = 0;j<2;j++){
        for(int i = 0;i<5;i++){
            spKarten1bis10[i][j].setTextureRect(sf::IntRect(j*CardHeight,i*CardWidth,CardHeight,CardWidth));
            spKarten1bis10[i][j].setScale(sf::Vector2f(CardScale, CardScale));
            spKarten1bis10[i][j].setOrigin(sf::Vector2f(CardHeight/2,CardWidth/2));
            spKarten1bis10[i][j].setPosition(sf::Vector2f(WindowWidth/6 + i*CardDistance + j*5*CardDistance, WindowHeight - 0.25 * CardHeightScaled));
            spKarten1bis10[i][j].setRotation(90);
        }
    }

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Red);

        // draw everything here...
        for(int j = 0;j<2;j++){
            for(int i = 0;i<5;i++)
                window.draw(spKarten1bis10[i][j]);
        }


        // end the current frame
        window.display();
    }
}


int main()
{
    //openWindow();
    drawGraphics();

    return 0;
}
