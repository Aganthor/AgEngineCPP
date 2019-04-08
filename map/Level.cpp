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
		mapGenerator.setMapWidth(map::WORLDMAP_WIDTH);
		mapGenerator.setMapHeight(map::WORLDMAP_HEIGHT);

		mapGenerator.generateMap();

		m_levelData.resize(mapGenerator.getMapWidth() * mapGenerator.getMapHeight());

		for (auto y = 0; y < mapGenerator.getMapHeight(); ++y)
		{
			for (auto x = 0; x < mapGenerator.getMapWidth(); ++x)
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


	/*
	TileInfo & Level::getTileInfo(int x, int y)
	{
		// TODO: insert return statement here
	}
	*/

}