#include "game.h"

Game::Game()
	: m_visualizer(m_window.getSize())
	, m_sortManager(&m_visualizer, m_window.getWindow())
{
	//Load Default settings && Textures
}
Game::Game(const sf::Vector2u& l_size, const std::string& l_name)
	: m_window(l_size, l_name)
	, m_visualizer(m_window.getSize())
	, m_sortManager(&m_visualizer, m_window.getWindow())
	{
	}

Game::~Game() {}

Window* Game::getWindow()
{
	return &m_window;
}

bool Game::HandleInput()
{
	//input
	if (m_visualizer.handleInput())
		return true;
	else return false;
}

void Game::Update()
{
	//Event System
	m_window.Update();
}

void Game::Render()
{
	//===Render se radi na m_sortManageru===//

	//Ovo je samo pocetni render prije nego se klikne space
	m_window.BeginDraw(sf::Color::Black);

	m_visualizer.draw(m_window.getWindow());

	m_window.EndDraw();
}

void Game::RestartClock()
{
	m_elapsed = m_clock.restart();
}

SortManager* Game::getSortManager()
{
	return &m_sortManager;
}