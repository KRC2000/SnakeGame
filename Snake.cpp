// SPDX-FileCopyrightText: 2023 Roman Kovalov rokosta@proton.me
// SPDX-License-Identifier: MIT

#include <iostream>
#include "Snake.hpp"

Snake::Snake(Level & level, int & score, float speed):level(&level), score(&score), tickdelay(1.f / speed)
{
	body_t.loadFromFile("res/body.png");
	head_t.loadFromFile("res/head.png");
	head.setTexture(&head_t);
	head.setSize({(float)head_t.getSize().x, (float)head_t.getSize().y});
	head.setOrigin(head_t.getSize().x / 2, head_t.getSize().y / 2);
	body_stamp.setTexture(body_t);
	segments.push_back({1, 0});
	segments.push_back({0, 0});

}

void Snake::Update(float delta)
{
	time_accumulator += delta;

	if (time_accumulator >= tickdelay)
	{


		time_accumulator = 0;

		if (!justAte)
			AdvanceBody();
		else
			Grow();

		MoveHead(desiredDirection);

		if (level->IsFieldFull(segments))
		{
			printf("You won! Wow!\n");
			PrintScore();
			exit(0);
		}

		if (!level->IsTilePositionInside(segments.front()))
		{
			printf("You hit the wall!\n");
			PrintScore();
			exit(0);
		}

		if (level->IsFoodHere(segments.front()))
		{
			level->RespawnFood(segments);
			*score += 1;
			justAte = true;
		}

		if (IsThereHeadBodyOverlap())
		{
			printf("You bit your tale!\n");
			PrintScore();
			exit(0);
		}

	}
}

std::vector<sf::Vector2i> Snake::getOccupiedTiles() const
{
	return segments;
}

bool Snake::IsThereHeadBodyOverlap()
{
	for (int i = 1; i < segments.size(); i++)
	{
		if (segments.front() == segments[i])
			return true;
	}

	return false;
}

void Snake::MoveHead(Snake::Direction direction)
{
	if ((previousDirection == Direction::EAST && direction == Direction::WEST) ||
		(previousDirection == Direction::WEST && direction == Direction::EAST) ||
		(previousDirection == Direction::SOUTH && direction == Direction::NORTH) ||
		(previousDirection == Direction::NORTH && direction == Direction::SOUTH))
	{
		MoveHead(previousDirection);
	}
	else
	{
		switch (direction)
		{
			case Snake::Direction::EAST:
				MoveHeadEast();
				break;
			case Snake::Direction::WEST:
				MoveHeadWest();
				break;
			case Snake::Direction::NORTH:
				MoveHeadNorth();
				break;
			case Snake::Direction::SOUTH:
				MoveHeadSouth();
				break;
		}
		previousDirection = direction;
	}
}

void Snake::MoveHeadNorth()
{
	segments.front() += {0, -1};
	head.setRotation(-90);
}

void Snake::MoveHeadSouth()
{
	segments.front() += {0, 1};
	head.setRotation(90);
}

void Snake::MoveHeadWest()
{
	segments.front() += {-1, 0};
	head.setRotation(180);
}

void Snake::MoveHeadEast()
{
	segments.front() += {1, 0};
	head.setRotation(0);
}


void Snake::AdvanceBody()
{
	for (int i = segments.size()-1; i > 0; i--)
	{
		segments[i] = segments[i-1];
	}
}

void Snake::Grow()
{
	segments.insert(segments.begin() + 1, segments.front());
	justAte = false;
}

void Snake::PrintScore()
{
	printf("Your score is: %i\n", *score);
}


void Snake::draw(sf::RenderTarget& target)
{
	head.setPosition({(float)(segments.front().x * level->TileTexture.getSize().x + head.getOrigin().x), (float)(segments.front().y * level->TileTexture.getSize().y + head.getOrigin().y)});
	target.draw(head);

	for (int i = 1; i < segments.size(); i++)
	{
		body_stamp.setPosition({(float)(segments[i].x * level->TileTexture.getSize().x), (float)(segments[i].y * level->TileTexture.getSize().y)});
		target.draw(body_stamp);
	}
}
