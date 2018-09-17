#include "Game.h"
#include "map/map.h"

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
  map::Map map;
       sf::Texture texture;
     sf::Sprite sprite;

     texture.loadFromFile("res/tiles/floor_vines_0_old.png");


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

    //    map.CreateMap(m_SFMLWindow);
    sprite.setPosition(0, 0);
    m_SFMLWindow.draw(sprite);
    sprite.setPosition(32, 0);
    m_SFMLWindow.draw(sprite);

     m_SFMLWindow.display();
  }
}
