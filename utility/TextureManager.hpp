#pragma once

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

//TODO: make it so that it indexes with tiletypes.

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
