#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Run()
{
	m_SFMLWindow.create(sf::VideoMode(800, 600), "AgEngine demo!");

	while (m_SFMLWindow.isOpen())
	{
		sf::Event event;

		while (m_SFMLWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_SFMLWindow.close();
		}
	}
}