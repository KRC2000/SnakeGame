// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: MIT

#include "SnakeGame.h"

SnakeGame::SnakeGame(sf::Vector2i size_in_tiles, float scale):Scale(scale), level(size_in_tiles, scale, "res/tile.png"), snake(level, scale)
{
    srand((unsigned) time(NULL));

    window.create(sf::VideoMode(level.Stamp.getGlobalBounds().width, level.Stamp.getGlobalBounds().height), "Snake Game");

    food_t.loadFromFile("res/food.png");
    food.setTexture(food_t);
    food.setScale(Scale, Scale);
    RespawnFood();
}

SnakeGame::~SnakeGame()
{

}

void SnakeGame::Run()
{

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Key::Left)
                    snake.direction = Snake::Direction::WEST;
                if (event.key.code == sf::Keyboard::Key::Right)
                    snake.direction = Snake::Direction::EAST;
                if (event.key.code == sf::Keyboard::Key::Up)
                    snake.direction = Snake::Direction::NORTH;
                if (event.key.code == sf::Keyboard::Key::Down)
                    snake.direction = Snake::Direction::SOUTH;
            }
        }


        snake.Update(Timer.restart().asSeconds());

        window.clear();
        level.Draw(window);
        window.draw(food);
        snake.draw(window);
        window.display();
    }

}

void SnakeGame::RespawnFood()
{
    food_location = {rand() % level.SizeTiles.x, rand() % level.SizeTiles.y};
    food.setPosition(food_location.x * level.TileTexture.getSize().x * Scale, food_location.y * level.TileTexture.getSize().x * Scale);
}

