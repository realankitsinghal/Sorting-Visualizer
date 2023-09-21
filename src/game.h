#pragma once
#include "window.h"
#include "SortManager.h"

class Game
{
public:
	Game();
	Game(const sf::Vector2u& l_size, const std::string& l_name);
	~Game();

	bool HandleInput();
	void Update();
	void Render();

	Window* getWindow();

	void RestartClock();

	SortManager* getSortManager();

private:
	Window m_window;
	Visualizer m_visualizer;
	SortManager m_sortManager;

	sf::Clock m_clock;
	sf::Time m_elapsed;
};