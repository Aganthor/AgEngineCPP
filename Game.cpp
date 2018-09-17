#include "Game.h"
#include "map/worldmap.h"

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

    m_SFMLWindow.display();
  }
}
