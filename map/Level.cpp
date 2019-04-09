#include "Level.hpp"

#include <utility>

#include <SFML/Graphics.hpp>

#include "BaseMapGenerator.hpp"
#include "MapConstants.hpp"
#include "TileType.hpp"

namespace map
{
	Level::Level()
	{
		loadTextureFiles();
	}


	void Level::generateLevel(BaseMapGenerator& mapGenerator)
	{
        m_levelWidth = mapGenerator.getMapWidth();
        int levelHeight = mapGenerator.getMapHeight();

        m_levelData.resize(m_levelWidth * levelHeight);

        for (auto y = 0; y < levelHeight; ++y)
		{
            for (auto x = 0; x < m_levelWidth; ++x)
			{
				float mapValue = mapGenerator.getValueAt(x, y);

				if ((mapValue >= -1.0) && (mapValue < -0.25)) //deep water
				{
					m_levelData.emplace_back(std::make_unique<TileInfo>(x, y, TileType::DEEP_WATER, false, false, false));
				}
				else if ((mapValue >= -0.25) && (mapValue < 0.0)) //shallow water
				{
					m_levelData.emplace_back(std::make_unique<TileInfo>(x, y, TileType::SHALLOW_WATER, false, false, false));
				}
				else if ((mapValue >= 0.0) && (mapValue < 0.0625)) //shore
				{
					m_levelData.emplace_back(std::make_unique<TileInfo>(x, y, TileType::SHORE, false, false, true));
				}
				else if ((mapValue >= 0.0625) && (mapValue < 0.1250)) //sand
				{
					m_levelData.emplace_back(std::make_unique<TileInfo>(x, y, TileType::SAND, false, false, true));
				}
				else if ((mapValue >= 0.1250) && (mapValue < 0.3750)) //grass
				{
					m_levelData.emplace_back(std::make_unique<TileInfo>(x, y, TileType::GRASS, false, false, true));
				}
				else if ((mapValue >= 0.3750) && (mapValue < 0.75)) //dirt
				{
					m_levelData.emplace_back(std::make_unique<TileInfo>(x, y, TileType::DIRT, false, false, true));
				}
				else if ((mapValue >= 0.75) && (mapValue < 1.0)) //rock
				{
					m_levelData.emplace_back(std::make_unique<TileInfo>(x, y, TileType::ROCK, false, false, false));
				}
				else //snow
				{
					m_levelData.emplace_back(std::make_unique<TileInfo>(x, y, TileType::SNOW, false, false, false));
				}
			}
		}
	}

	void Level::renderLevel(sf::RenderWindow& window)
	{
		sf::Sprite sprite;

		for (auto &tileInfo: m_levelData)
		{
            sprite.setTexture(m_textureManager.getTexture("grass"));
            //TODO : doesn't seem to work!
            sprite.setPosition((*tileInfo).x, (*tileInfo).y);
            window.draw(sprite);

		}
	}
	
	void Level::loadTextureFiles()
	{
		m_textureManager.addTexture("deep_water");
		m_textureManager.addTexture("shallow_water");
		m_textureManager.addTexture("dirt");
		m_textureManager.addTexture("grass");
		m_textureManager.addTexture("rock");
		m_textureManager.addTexture("sand");
		m_textureManager.addTexture("shore");
		m_textureManager.addTexture("snow");
	}

    //
    // Used to get the specific tile information at location x and y.
    //
	TileInfo & Level::getTileInfo(int x, int y)
	{
        return *m_levelData[y * m_levelWidth + x];
	}

    TileType getTileType(const std::string& tilename)
    {
        if (tilename == "deep_water")
            return TileType::DEEP_WATER;
        else if (tilename == "shallow_water")
            return TileType::SHALLOW_WATER;
        else if (tilename == "dirt")
            return TileType::DIRT;
        else if (tilename == "grass")
            return TileType::GRASS;
        else if (tilename == "rock")
            return TileType::ROCK;
        else if (tilename == "sand")
            return TileType::SAND;
        else if (tilename == "shore")
            return TileType::SHORE;
        else if (tilename == "snow")
            return TileType::SNOW;
        else
            return TileType::NONE;
    }


}
