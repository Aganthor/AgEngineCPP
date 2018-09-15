#pragma once

#include <SFML/Window.hpp>

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
  sf::Window m_SFMLWindow;
};
