// SPDX-FileCopyrightText: 2023 Roman Kovalov rokosta@proton.me
// SPDX-License-Identifier: MIT

#include "Level.h"

Level::Level(sf::Vector2i size_in_tiles, float scale, std::string tile_texture_path) : SizeTiles(size_in_tiles)
{
    TileTexture.loadFromFile((tile_texture_path));
    TileTexture.setRepeated(true);
    Stamp.setTexture(&TileTexture);
    Stamp.setSize({size_in_tiles.x * (float)TileTexture.getSize().x, size_in_tiles.y * (float)TileTexture.getSize().y});
    Stamp.setTextureRect({0, 0, (int)Stamp.getSize().x, (int)Stamp.getSize().y});
    Stamp.setScale(scale, scale);
}

void Level::Draw(sf::RenderTarget& target)
{
    target.draw(Stamp);
}
