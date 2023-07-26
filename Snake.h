// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: MIT

#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Level.h"
/**
 * @todo write docs
 */
class Snake
{
public:
    enum Direction
    {
        NORTH, SOUTH, WEST, EAST
    };
    /**
     * Default constructor
     */
    Snake(Level & level, float scale);
    void Update(float delta);
    void draw(sf::RenderTarget & target);

    Level* level = NULL;
    Direction direction = Snake::Direction::EAST;
    std::vector<sf::Vector2i> segments;
    float scale;
    sf::Sprite stamp;
    sf::Texture body_t;
    sf::Texture head_t;
    float time_accumulator = 0;
    float tickdelay = 1;
};

#endif // SNAKE_H
