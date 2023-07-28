// SPDX-FileCopyrightText: 2023 Roman Kovalov rokosta@proton.me
// SPDX-License-Identifier: MIT

#include "Level.h"

Level::Level(sf::Vector2i size_in_tiles,std::string tile_texture_path) : SizeTiles(size_in_tiles)
{
	TileTexture.loadFromFile((tile_texture_path));
	TileTexture.setRepeated(true);
	Stamp.setTexture(&TileTexture);
	Stamp.setSize({size_in_tiles.x * (float)TileTexture.getSize().x, size_in_tiles.y * (float)TileTexture.getSize().y});
	Stamp.setTextureRect({0, 0, (int)Stamp.getSize().x, (int)Stamp.getSize().y});

	FoodTexture.loadFromFile("res/food.png");
	Food.setTexture(FoodTexture);
}

void Level::RespawnFood(std::vector<sf::Vector2i> occupiedTiles)
{
	std::vector<sf::Vector2i>::iterator searchResult;
	do
	{
		FoodTilePosition = {rand() % SizeTiles.x, rand() % SizeTiles.y};
		searchResult = std::find(occupiedTiles.begin(), occupiedTiles.end(), FoodTilePosition);

	}
	while (searchResult != occupiedTiles.end());

	Food.setPosition(FoodTilePosition.x * TileTexture.getSize().x, FoodTilePosition.y * TileTexture.getSize().x);
}

bool Level::IsFieldFull(std::vector<sf::Vector2i> occupiedTiles) const
{
	for (int y = 0; y < SizeTiles.y; y++)
	{
		for (int x = 0; x < SizeTiles.x; x++)
		{
			std::vector<sf::Vector2i>::iterator searchResult;
			searchResult = std::find(occupiedTiles.begin(), occupiedTiles.end(), sf::Vector2i(x, y));
			if (searchResult == occupiedTiles.end())
				return false;
		}
	}

	return true;
}


bool Level::IsTilePositionInside(sf::Vector2i pos) const
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= SizeTiles.x || pos.y >= SizeTiles.y)
		return false;
	return true;
}

bool Level::IsFoodHere(sf::Vector2i pos) const
{
	if (FoodTilePosition == pos)
		return true;
	return false;
}


void Level::Draw(sf::RenderTarget& target)
{
	target.draw(Stamp);
	target.draw(Food);
}
