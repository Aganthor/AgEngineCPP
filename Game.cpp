#include "Game.h"
#include "map/worldmap.h"

#include <SFML/Graphics.hpp>

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
  m_SFMLWindow.create(sf::VideoMode(800, 600), "AgEngine demo!");
}

void Game::run()
{
  map::WorldMap worldmap;

  worldmap.generateMap();

  sf::Texture texture;
  sf::Sprite sprite;

  texture.loadFromFile("worldmap.bmp");
  sprite.setTexture(texture);

  while (m_SFMLWindow.isOpen())
  {
    sf::Event event;

    while (m_SFMLWindow.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        m_SFMLWindow.close();
    }

    //Clear the window.
    m_SFMLWindow.clear(sf::Color::Black);

    m_SFMLWindow.draw(sprite);

    m_SFMLWindow.display();
  }
}
