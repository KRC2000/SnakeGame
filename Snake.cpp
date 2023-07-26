// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: MIT

#include <iostream>
#include "Snake.h"

Snake::Snake(Level & level, float scale):level(&level), scale(scale)
{
    body_t.loadFromFile("res/body.png");
    head_t.loadFromFile("res/head.png");
    segments.push_back({1, 0});
    segments.push_back({0, 0});

}

void Snake::Update(float delta)
{
    time_accumulator += delta;
    // printf("%f\n", time_accumulator);
    if (time_accumulator >= tickdelay)
    {
        time_accumulator = 0;

        for (int i = segments.size()-1; i > 0; i--)
        {
            segments[i] = segments[i-1];
        }


        switch (direction){
            case Snake::Direction::EAST:
                segments.front() += {1, 0};
                break;
            case Snake::Direction::WEST:
                segments.front() += {-1, 0};
                break;
            case Snake::Direction::NORTH:
                segments.front() += {0, -1};
                break;
            case Snake::Direction::SOUTH:
                segments.front() += {0, 1};
                break;

        }
    }
}


void Snake::draw(sf::RenderTarget& target)
{
    stamp.setTexture(head_t);
    stamp.setScale(scale, scale);
    stamp.setPosition({segments.front().x * level->TileTexture.getSize().x * scale, segments.front().y * level->TileTexture.getSize().y * scale});
    target.draw(stamp);
    for (int i = 1; i < segments.size(); i++)
    {
        stamp.setTexture(body_t);
        stamp.setPosition({segments[i].x * level->TileTexture.getSize().x * scale, segments[i].y * level->TileTexture.getSize().y * scale});
        target.draw(stamp);
    }
}
