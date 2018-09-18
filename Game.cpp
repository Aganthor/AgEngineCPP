#include "Game.h"
#include "map/worldmap.h"

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

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
  ImGui::SFML::Init(m_SFMLWindow);
}

void Game::run()
{
  map::WorldMap worldmap;

  worldmap.generateMap();

  sf::Texture texture;
  sf::Sprite sprite;

  texture.loadFromFile("worldmap.bmp");
  sprite.setTexture(texture);

  //Prepare ImGui stuff
  sf::Color bgColor;

  float color[3] = { 0.f, 0.f, 0.f };

  // let's use char array as buffer, see next part
  // for instructions on using std::string with ImGui
  char windowTitle[255] = "ImGui + SFML = <3";

  m_SFMLWindow.setTitle(windowTitle);
  m_SFMLWindow.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
  sf::Clock deltaClock;

  while (m_SFMLWindow.isOpen())
  {
    sf::Event event;

    while (m_SFMLWindow.pollEvent(event))
    {
      ImGui::SFML::ProcessEvent(event);
      if (event.type == sf::Event::Closed)
        m_SFMLWindow.close();
    }
    ImGui::SFML::Update(m_SFMLWindow, deltaClock.restart());

    ImGui::Begin("Sample window"); // begin window

    // Background color edit
    if (ImGui::ColorEdit3("Background color", color)) {
      // this code gets called if color value changes, so
      // the background color is upgraded automatically!
      bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
      bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
      bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
    }

    // Window title text edit
    ImGui::InputText("Window title", windowTitle, 255);

    if (ImGui::Button("Update window title")) {
      // this code gets if user clicks on the button
      // yes, you could have written if(ImGui::InputText(...))
      // but I do this to show how buttons work :)
      m_SFMLWindow.setTitle(windowTitle);
    }
    ImGui::End(); // end window

    //Clear the window.
    m_SFMLWindow.clear(sf::Color::Black);

    m_SFMLWindow.draw(sprite);
    ImGui::SFML::Render(m_SFMLWindow);

    m_SFMLWindow.display();
  }
}
