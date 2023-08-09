// SPDX-FileCopyrightText: 2023 Roman Kovalov rokosta@proton.me
// SPDX-License-Identifier: MIT

#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <SFML/Graphics.hpp>

/**
 * @todo write docs
 */
class Level
{
public:
	/**
	 * Default constructor
	 */
	Level(sf::Vector2i size_in_tiles, std::string tile_texture_path);
	void RespawnFood(std::vector<sf::Vector2i> occupiedTiles);
	bool IsFieldFull(std::vector<sf::Vector2i> occupiedTiles) const;
	bool IsTilePositionInside(sf::Vector2i pos) const;
	bool IsFoodHere(sf::Vector2i pos) const;
	void Draw(sf::RenderTarget& target);

	sf::RectangleShape Stamp;
	sf::Vector2i SizeTiles;
	sf::Texture TileTexture, FoodTexture;

	sf::Sprite Food;
	sf::Vector2i FoodTilePosition;
};

#endif // LEVEL_H
