#include "ai.h"

//#include <SFML/Graphics.hpp>

#include <stdlib.h>
#include <string>
#include <iostream>

int main() {
    /*// Render the window 200x200
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
        */
    //}
    // TESTING WORD_WRAPPER FUNCTION //
    AI ai;
    std::string quote = "There are several government aid programs available in California to assist individuals and families in need. Some of the key programs include: 1. CalFresh (formerly known as food stamps): Provides eligible low-income individuals and families with funds for purchasing food. 2. Medi-Cal: California's version of the Medicaid program, which offers free or low-cost health coverage to eligible low-income individuals and families. 3. CalWORKs: Provides temporary cash assistance to low-income families with children to help meet their basic needs. 4. Housing Choice Voucher Program (Section 8): Assists low-income individuals";
        // to live 2. deliberately, to front only the essential 3. facts of life, 4. and see if I could not learn what it had to teach, and not, when I came to die, discover that I had not lived. I did not wish to live what was not life, living is so dear; nor did I wish to practise resignation, unless it was quite necessary. I wanted to live deep and suck out all the marrow of life, to live so sturdily and Spartan-like as to put to rout all that was not life, to cut a broad swath and shave close, to drive life into a corner, and reduce it to its lowest terms...";
    std::string ostr = ai.word_wrapper(quote);
    std::cout << ostr;
    return 0;
}
