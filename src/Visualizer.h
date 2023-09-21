#pragma once
#include <SFML/Graphics.hpp>

struct Stupac
{
	Stupac()
		: col(sf::Quads, 4)
		, colour(sf::Color::White)
		{}

	void changeColour(sf::Color l_colour)
	{
		for (int i = 0; i < 4; i++)
			this->col[i].color = l_colour;
	}

	sf::VertexArray col;
	sf::Color colour;
};

class Visualizer
{
public:
	Visualizer(sf::Vector2u l_winSize);
	~Visualizer();

	bool handleInput();
	void draw(sf::RenderWindow* l_window);

	void setColumnWidth(int l_width);
	void setHeightMultiplier(int l_heightMultiplier);

	void reDraw();

	int* getArray();
	Stupac* getStupci();
	int getColNum();

private:
	int* m_array;
	Stupac* m_stupci;

	int m_nStupacWidth;
	int m_nHeightMultiplier;
	int m_nColNum;

	sf::Vector2u m_winSize;

	void Setup();
	void ShuffleArray();

};

