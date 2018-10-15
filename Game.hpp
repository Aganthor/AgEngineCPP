#pragma once

#include <SFML/Graphics.hpp>

///////////////////////////////////////////////////////////////////////////////
// Main game class. Will hold about everything! Will also be responsible to
// manage the window.
///////////////////////////////////////////////////////////////////////////////

namespace map
{
class WorldMap;
}

class Game
{
public:
  Game();
  ~Game();


  void init();
  void run();
  void handleEvent();
  void update(float dt);
  void render();
  

private:
  void showGeneratorOptions();
  void renderMap(map::WorldMap& map);

  void loadTextures();

private:
  sf::RenderWindow m_SFMLWindow;

  sf::Texture m_waterTexture;
  sf::Texture m_sandTexture;
  sf::Texture m_grassTexture;
  sf::Texture m_dirtTexture;
  sf::Texture m_rockTexture;
};
