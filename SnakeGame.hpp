// SPDX-FileCopyrightText: 2023 Roman Kovalov rokosta@proton.me
// SPDX-License-Identifier: MIT

#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <random>
#include <SFML/Graphics.hpp>

#include "Level.hpp"
#include "Snake.hpp"
/**
 * @todo write docs
 */
class SnakeGame
{
public:

	SnakeGame(sf::Vector2i size_in_tiles = {5, 5}, float scale = 2, float speed = 2);
	~SnakeGame();
	void Run();

	sf::View view;
	float Scale;
	sf::RenderWindow window;
	Level level;
	Snake snake;
	int Score = 0;

	sf::Clock Timer;
};

#endif // SNAKEGAME_H
