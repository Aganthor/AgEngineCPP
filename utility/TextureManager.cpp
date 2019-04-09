#include "TextureManager.hpp"

#include <utility>

sf::Texture& TextureManager::getTexture(const std::string & name)
{
	return m_textureMap[name];
}

void TextureManager::addTexture(const std::string & name)
{
	std::string fileName = "res/tiles/" + name + ".png";
	sf::Texture texture;

	if (!texture.loadFromFile(fileName))
	{ 
		//TODO: log error
	}
	else
	{
        m_textureMap.insert(std::make_pair(name, texture));
	}
}

void TextureManager::removeTexture(const std::string & name)
{
	
	auto rem = m_textureMap.erase(name);
	if (rem < 0)
	{
		//TODO : log error...
	}
	
}
