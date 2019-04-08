#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../utility/TextureManager.hpp"
#include "Tileinfo.hpp"

namespace map
{
    class BaseMapGenerator;
}


//
//A Level class to hold information concerning a level i.e. map, objects.
//

namespace map
{
    class Level
    {
    public:
        Level();
        ~Level() {};
    
        void generateLevel(BaseMapGenerator& mapGenerator);

        void renderLevel(sf::RenderWindow& window);

    private:
        void loadTextureFiles();

    private:
        std::vector<std::unique_ptr<TileInfo>> m_levelData;        
        TextureManager m_textureManager;
    };
}
