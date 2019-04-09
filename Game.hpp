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


  void init();
  void run();
  void handleEvent();
  void update(float dt);
  void render();
  

private:
  void showGeneratorOptions();

private:
  sf::RenderWindow m_SFMLWindow;
};
