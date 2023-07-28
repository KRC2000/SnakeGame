// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: MIT

#include "SnakeGame.h"

SnakeGame::SnakeGame(sf::Vector2i size_in_tiles, float scale):Scale(scale), level(size_in_tiles, "res/tile.png"), snake(level)
{
	srand((unsigned) time(NULL));

	window.create(sf::VideoMode(level.Stamp.getGlobalBounds().width, level.Stamp.getGlobalBounds().height), "Snake Game");


	level.RespawnFood(snake.getOccupiedTiles());
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
					snake.desiredDirection = Snake::Direction::WEST;
				if (event.key.code == sf::Keyboard::Key::Right)
					snake.desiredDirection = Snake::Direction::EAST;
				if (event.key.code == sf::Keyboard::Key::Up)
					snake.desiredDirection = Snake::Direction::NORTH;
				if (event.key.code == sf::Keyboard::Key::Down)
					snake.desiredDirection = Snake::Direction::SOUTH;
			}
		}


		snake.Update(Timer.restart().asSeconds());

		window.clear();
		level.Draw(window);

		snake.draw(window);
		window.display();
	}

}


