#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width = 1000, height = 800;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");       // Create the SFML window
    sf::CircleShape shape(100.f);       // Create an SFML circle
    // Shape manipulation
    shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(width / 2, height / 2);
    //RectangleShape rect()

    /* Main loop/Game loop. Needed for every program.
    *  The event loop is also necessary for proper event handling.
       You must clear/draw/display for new frames.                  */ 
    while (window.isOpen())
    {
        int i = 0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        }
        window.clear(sf::Color::Cyan);
        window.draw(shape);
        window.display();
    }
    return 0;
}