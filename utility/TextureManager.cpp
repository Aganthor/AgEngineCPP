#include "TextureManager.hpp"

#include <utility>

sf::Texture& TextureManager::getTexture(map::TileType type)
{
	return m_textureMap[type];
}

void TextureManager::addTexture(const std::string& name, map::TileType type)
{
	std::string fileName = "res/tiles/" + name + ".png";
	sf::Texture texture;

	if (!texture.loadFromFile(fileName))
	{
		//TODO: log error
	}
	else
	{
        m_textureMap.insert(std::make_pair(type, texture));
	}
}

void TextureManager::removeTexture(map::TileType type)
{

	auto rem = m_textureMap.erase(type);
	if (rem < 0)
	{
		//TODO : log error...
	}

}
