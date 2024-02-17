#include "ai.h"

#include <SFML/Graphics.hpp>

#include <stdlib.h>
#include <string>
#include <iostream>

int main() {
    // Render the window 200x200
    sf::RenderWindow window(sf::VideoMode(), "Fy, your financial guide!",
            sf::Style::Fullscreen);
    // Create the texture for the background
    sf::Texture school;

    // Make sure you can load the picture (and load it into the texture)
    if(!school.loadFromFile("../res/fy.png")) {
        std::cerr << "The file could not be loaded." << std::endl;
    }
    school.setSmooth(true);
    // Create the sprite
    sf::Sprite sprite;

    // Apply the texture to the sprite (now we have a usable object!)
    sprite.setTexture(school);

    sprite.setPosition(0, 0);
    sprite.setScale(0.54, 0.54);

    // Application loop
    while (window.isOpen())
    {
        // If the user does an action equivalent to closing the application,
        // then close the application
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
