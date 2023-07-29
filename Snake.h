// SPDX-FileCopyrightText: 2023 Roman Kovalov rokosta@proton.me
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
	Snake(Level & level);
	void Update(float delta);
	std::vector<sf::Vector2i> getOccupiedTiles() const;
	bool IsThereHeadBodyOverlap();
	void MoveHead(Snake::Direction direction);
	void MoveHeadNorth();
	void MoveHeadSouth();
	void MoveHeadWest();
	void MoveHeadEast();
	void AdvanceBody();
	void Grow();
	void draw(sf::RenderTarget & target);

	Level* level = NULL;
	Direction desiredDirection = Snake::Direction::EAST;
	Direction previousDirection = Snake::Direction::EAST;
	std::vector<sf::Vector2i> segments;
	sf::Sprite body_stamp;
	sf::RectangleShape head;
	sf::Texture body_t, head_t;
	float time_accumulator = 0;
	float tickdelay = 1;
	bool justAte = false;
};

#endif // SNAKE_H
