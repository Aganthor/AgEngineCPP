#pragma once

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "../map/TileType.hpp"

//TODO: make it so that it indexes with tiletypes.

class TextureManager
{
public:
	TextureManager() {}
	~TextureManager() {}

    sf::Texture& getTexture(map::TileType type);

    void addTexture(const std::string& name, map::TileType type);
    void removeTexture(map::TileType type);


private:
    std::map<map::TileType, sf::Texture> m_textureMap;
};
