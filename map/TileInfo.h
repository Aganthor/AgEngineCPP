#pragma once

#include <cstdint>

namespace map
{
    enum class TextureID: unsigned char
    {
        WATER_TILE = 1;
        SHORE_TILE = 2;
        SAND_TILE = 3;
        GRASS_TILE = 4;
        DIRT_TILE = 5;
        ROCK_TILE = 6;
        SNOW_TILE = 7;
    };

    struct TileInfo
    {
        int x;
        int y;
        TextureID tileType;
        bool explored;
        bool blockView;
        bool isWall;
    };
}