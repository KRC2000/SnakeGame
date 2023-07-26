// SPDX-FileCopyrightText: 2023 Roman Kovalov rokosta@proton.me
// SPDX-License-Identifier: MIT

#include "Level.h"

Level::Level(sf::Vector2i size_in_tiles, std::string tile_texture_path) : SizeTiles(size_in_tiles)
{
    TileTexture.loadFromFile((tile_texture_path));
    TileTexture.setRepeated(true);
    Stamp.setTexture(&TileTexture);
    Stamp.setSize({50, 50});
    Stamp.setTextureRect({0, 0, (int)Stamp.getSize().x, (int)Stamp.getSize().y});
}

void Level::Draw(sf::RenderTarget& target)
{
    // for (int y = 0; y < SizeTiles.y; y++)
    // {
    //     for (int x = 0; x < SizeTiles.x; x++)
    //     {
    //         StampSprite.setPosition(x * StampSprite.getGlobalBounds().width, y * StampSprite.getGlobalBounds().height);
    //         target.draw(StampSprite);
    //     }
    // }
    target.draw(Stamp);
}
