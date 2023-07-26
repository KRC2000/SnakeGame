#include <iostream>
#include <SFML/Graphics.hpp>

#include "Level.h"

int main()
{
    Level level({15, 5}, "res/tile.png");

    sf::RenderWindow window(sf::VideoMode(level.SizeTiles.x * level.Stamp.getSize().x, level.SizeTiles.y * level.Stamp.getSize().y), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        level.Draw(window);
        window.display();
    }

    return 0;
}
