#include "Game.h"
#include "map/worldmap.h"

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

#include <SFML/Graphics.hpp>

float frequency = 2.0;
float flatScale = 0.125;
float flatBias = -0.75;
float perlinFreq = 0.5;
float perlinPers = -0.25;
bool regenerateMap = false;

constexpr int MAP_MAX_WIDTH = 256;
constexpr int MAP_MAX_HEIGHT = 256;

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

  m_SFMLWindow.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.

  sf::Clock deltaClock;
  bool showGeneratorWindow = false;

  while (m_SFMLWindow.isOpen())
  {
    sf::Event event;

    while (m_SFMLWindow.pollEvent(event))
    {
      ImGui::SFML::ProcessEvent(event);

      if (event.type == sf::Event::Closed)
        m_SFMLWindow.close();

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        showGeneratorWindow = true;
    }
    ImGui::SFML::Update(m_SFMLWindow, deltaClock.restart());

    if (showGeneratorWindow)
    {
      showGeneratorOptions();
      worldmap.setBaseFreq(frequency);
      worldmap.setFlatBias(flatBias);
      worldmap.setFlatScale(flatScale);
      worldmap.setPerlinFreq(perlinFreq);
      worldmap.setPerlinPers(perlinPers);

      if (regenerateMap)
      {
        worldmap.generateMap();
        regenerateMap = false;
      }
    }
    //    ImGui::ShowDemoWindow();

    //Clear the window.
    m_SFMLWindow.clear(sf::Color::Black);

    m_SFMLWindow.draw(sprite);
    ImGui::SFML::Render(m_SFMLWindow);

    m_SFMLWindow.display();
  }

  ImGui::SFML::Shutdown();
}

void Game::showGeneratorOptions()
{
  ImGui::Begin("mapGenerator options");

  ImGui::InputFloat("baseFlatterrain frequency", &frequency);
  ImGui::SliderFloat("Flat terrain scale", &flatScale, 0.0f, 10.0f);
  ImGui::SliderFloat("Flat terrain bias", &flatBias, 0.0f, 10.0f);
  ImGui::SliderFloat("Perlin frequency", &perlinFreq, 0.0f, 10.0f);
  ImGui::SliderFloat("Perlin persistence", &perlinPers, 0.0f, 10.0f);

  if (ImGui::Button("Regenerate map"))
    regenerateMap = true;

  ImGui::End();
}

void Game::loadTextures()
{
  m_waterTexture.loadFromFile("res/tiles/shoals_shallow_water_10.png");
  m_sandTexture.loadFromFile("res/tiles/sand.png");
  m_grassTexture.loadFromFile("res/tiles/grass.png");
  m_dirtTexture.loadFromFile("res/tiles/dirt.png");
  m_rockTexture.loadFromFile("res/tiles/rock.png");
}

void Game::renderMap()
{
  //   renderer.AddGradientPoint (-0.6000, utils::Color (  0,   0, 128, 255)); // deeps
  // renderer.AddGradientPoint ( 0.0625, utils::Color (240, 240,  64, 255)); // sand
  // renderer.AddGradientPoint ( 0.1250, utils::Color ( 32, 160,   0, 255)); // grass
  // renderer.AddGradientPoint ( 0.3750, utils::Color (224, 224,   0, 255)); // dirt
  // renderer.AddGradientPoint ( 0.7500, utils::Color (128, 128, 128, 255)); // rock

  sf::Sprite sprite;

  for (auto x = 0; x < MAP_MAX_WIDTH; ++x)
  {
    for (auto y = 0; y < MAP_MAX_HEIGHT; ++y)
    {
    }
  }
}
