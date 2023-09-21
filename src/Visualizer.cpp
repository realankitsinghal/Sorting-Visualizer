#include "Visualizer.h"

Visualizer::Visualizer(sf::Vector2u l_winSize)
	: m_stupci(nullptr), m_array(nullptr)
{
	m_winSize = l_winSize;

	m_nStupacWidth = 4;
	m_nHeightMultiplier = 2;

	Setup();
}

Visualizer::~Visualizer()
{
	delete[] m_stupci;
	delete[] m_array;
}

bool Visualizer::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		return true;
	else return false;
}

void Visualizer::draw(sf::RenderWindow* l_window)
{
	for (int i = 0; i < m_nColNum; i++)
	{
		l_window->draw(m_stupci[i].col);
	}
}

void Visualizer::reDraw()
{
	delete[] m_stupci;
	m_stupci = nullptr;

	m_stupci = new Stupac[m_nColNum];

	for (int i = 0; i < m_nColNum; i++)
	{
		const int x = i * m_nStupacWidth;

		int Height = (int)m_winSize.y - m_array[i] * m_nHeightMultiplier;

		Stupac temp;
		temp.col[0] = sf::Vector2f(x, m_winSize.y);
		temp.col[1] = sf::Vector2f(x + m_nStupacWidth, m_winSize.y);
		temp.col[2] = sf::Vector2f(x + m_nStupacWidth, Height);
		temp.col[3] = sf::Vector2f(x, Height);

		m_stupci[i] = temp;
	}
}

void Visualizer::Setup()
{
	//Clear memory and set to NULL
	delete[] m_stupci;
	m_stupci = nullptr;

	m_nColNum = (int)m_winSize.x / m_nStupacWidth;

	//Fill array
	m_array = new int[m_nColNum];

	for (int i = 0; i < m_nColNum; i++)
	{
		m_array[i] = i + 1;
	}

	ShuffleArray();

	//Allocate to an array of Stupci
	m_stupci = new Stupac[m_nColNum];

	//Create Stupac
	for (int i = 0; i < m_nColNum; i++)
	{
		const int x = i * m_nStupacWidth;

		int Height = (int)m_winSize.y - m_array[i] * m_nHeightMultiplier;

		Stupac temp;
		temp.col[0] = sf::Vector2f(x,						m_winSize.y);
		temp.col[1] = sf::Vector2f(x + m_nStupacWidth,		m_winSize.y);
		temp.col[2] = sf::Vector2f(x + m_nStupacWidth,		Height);
		temp.col[3] = sf::Vector2f(x,						Height);

		m_stupci[i] = temp;
	}
}

void Visualizer::ShuffleArray()
{
	if (m_array != nullptr)
	{
		std::random_shuffle(m_array, m_array + m_nColNum);
	}
	else printf("m_array = nullptr");
}

void Visualizer::setColumnWidth(int l_width) { m_nStupacWidth = l_width; Setup(); }
void Visualizer::setHeightMultiplier(int l_heightMultiplier) { m_nHeightMultiplier = l_heightMultiplier; }

int* Visualizer::getArray() { return m_array; }
Stupac* Visualizer::getStupci() { return m_stupci; }
int Visualizer::getColNum() { return m_nColNum; }