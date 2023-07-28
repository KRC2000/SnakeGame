// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: MIT

#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <random>
#include <SFML/Graphics.hpp>

#include "Level.h"
#include "Snake.h"
/**
 * @todo write docs
 */
class SnakeGame
{
public:

	SnakeGame(sf::Vector2i size_in_tiles, float scale);
	~SnakeGame();
	void Run();

	float Scale;
	sf::RenderWindow window;
	Level level;
	Snake snake;


	sf::Clock Timer;
};

#endif // SNAKEGAME_H
