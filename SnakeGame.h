// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: MIT

#ifndef SNAKEGAME_H
#define SNAKEGAME_H

/**
 * @todo write docs
 */
class SnakeGame
{
public:
    /**
     * Default constructor
     */
    SnakeGame();

    /**
     * Destructor
     */
    ~SnakeGame();

    sf::Vector2f Scale;
    sf::RenderWindow window;
    Level level;
};

#endif // SNAKEGAME_H
