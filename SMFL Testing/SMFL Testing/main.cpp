#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void screenBounce(sf::CircleShape* circle, int* x_Offset, int* y_Offset, sf::RenderWindow* window) {
    circle->move(*x_Offset, *y_Offset);
    if (circle->getPosition().x + circle->getLocalBounds().width / 2 >= window->getSize().x)
        *x_Offset = -*x_Offset;
    if (circle->getPosition().x - circle->getLocalBounds().width / 2 <= 0)
        *x_Offset = -*x_Offset;
    if (circle->getPosition().y + circle->getLocalBounds().height / 2 >= window->getSize().y)
        *y_Offset = -*y_Offset;
    if (circle->getPosition().y - circle->getLocalBounds().height / 2 <= 0)
        *y_Offset = -*y_Offset;
}

int main()
{
    int width = 1000, height = 800;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");   // Create the SFML window
    window.setFramerateLimit(60);
    
    // Shape manipulation
    sf::CircleShape circle(25.f);   // Create an SFML circle
    circle.setOrigin(circle.getLocalBounds().width / 2, circle.getLocalBounds().height / 2);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(100, 100);
    std::vector<sf::Shape*> trail;
    int xSpeed = 5, ySpeed = 5;
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
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(circle);
        screenBounce(&circle, &xSpeed, &ySpeed, &window);
        window.display();
        printf("xSpeed: %d, ySpeed: %d\n", xSpeed, ySpeed);
    }
    return 0;
}