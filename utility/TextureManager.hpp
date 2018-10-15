#pragma once

#include <map>
#include <string>

#include <sfml/Graphics.hpp>

class TextureManager
{
public:
	TextureManager() {}
	~TextureManager() {}

	sf::Texture& getTexture(const std::string& name);

	void addTexture(const std::string& name);
	void removeTexture(const std::string& name);


private:
	std::map<std::string, sf::Texture> m_textureMap;
};