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
    void Draw(sf::RenderTarget& target);

    sf::RectangleShape Stamp;
    sf::Vector2i SizeTiles;
    sf::Texture TileTexture;

};

#endif // LEVEL_H
