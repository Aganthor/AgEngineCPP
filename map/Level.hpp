#pragma once

#include <vector>
#include <memory>

#include "Tileinfo.hpp"
#include "../utility/TextureManager.hpp"

//TODO: level class should not hold onto a map generator...
//TODO: It should only be passed by reference within the generateLevel function.


//https://codereview.stackexchange.com/questions/87367/texture-managing
//http://gameprogrammingpatterns.com/service-locator.html

namespace sf
{
	class RenderWindow;
}

namespace map
{
	//
	//Forward declarations
	//
	class BaseMapGenerator;


	//
	// Level class will represent the actual level to be used for logic
	// and rendering. 
	//
	class Level
	{
	public:
		Level();
		~Level();

		void generateLevel(BaseMapGenerator& mapGenerator);
		void renderLevel(sf::RenderWindow& window);
		//void saveLevel();
		//void loadLevel();

		TileInfo& getTileInfo(int x, int y);

	private:
		void loadTextureFiles();
		
	private:
		using TilePtr = std::unique_ptr<TileInfo>;
		std::vector<TilePtr> m_levelData;

		TextureManager m_textureManager;
	};
}
