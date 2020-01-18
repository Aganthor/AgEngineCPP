#include "Game.hpp"

#include <iostream>

#include "map/WorldMapGenerator.hpp"
#include "map/Level.hpp"

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
constexpr int TILE_SIZE = 32;

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


//
// WIll handle keyboard and mouse input!
//
void Game::handleEvent(sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		std::cout << "Zooming in..." << m_zoomFactor << std::endl;
		m_zoomFactor -= 0.1f;
		if (m_zoomFactor < 0.f)
			m_zoomFactor = 0.f;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		std::cout << "Zooming out..." << m_zoomFactor << std::endl;
		m_zoomFactor += 0.1f;
		if (m_zoomFactor > 5.f)
			m_zoomFactor = 5.f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_moveX -= 50.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_moveX += 50.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_moveY -= 50.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_moveY += 50.f;
	}


}

//
// Will update the game logic.
//
void Game::update(float dt)
{
}

//
// Render the game!
//
void Game::render()
{
}

//
// The main game loop!
//
void Game::run()
{
	map::WorldMapGenerator worldMap ( MAP_MAX_WIDTH, MAP_MAX_HEIGHT );
	
	worldMap.setSeed(128);
	worldMap.setOctaves(2);
	worldMap.setScale(1.0f);
	worldMap.setOffset(sf::Vector2f(5,5));
	worldMap.setLacunarity(0.456f);
	worldMap.setPersistance(1.2f);
	
	worldMap.generateMap();

    map::Level level;

    level.generateLevel(worldMap);
	
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

			handleEvent(event);
		}
		ImGui::SFML::Update(m_SFMLWindow, deltaClock.restart());
		
		if (showGeneratorWindow) 
		{
			showGeneratorOptions();
			
			if (regenerateMap) 
			{
				worldMap.setScale(flatScale);
				worldMap.setPersistance(perlinPers);
				regenerateMap = false;
			}
		}
		//    ImGui::ShowDemoWindow();
		
		// Clear the window.
		m_SFMLWindow.clear(sf::Color::Black);
		
        
		sf::View view;

		//view.reset(sf::FloatRect(200.f, 200.f, 300.f, 200.f));
		view.setSize(800.f, 600.f);

		view.zoom(m_zoomFactor);

		view.move(m_moveX, m_moveY);

		m_SFMLWindow.setView(view);

		level.renderLevel(m_SFMLWindow);
		
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

