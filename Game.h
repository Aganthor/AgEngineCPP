#pragma once

#include <SFML/Graphics.hpp>

///////////////////////////////////////////////////////////////////////////////
// Main game class. Will hold about everything! Will also be responsible to
// manage the window.
///////////////////////////////////////////////////////////////////////////////

class Game
{
public:
  Game();
  ~Game();


  void run();
  void init();

private:
  sf::RenderWindow m_SFMLWindow;
};
