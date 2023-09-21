#include "SortManager.h"

SortManager::SortManager(Visualizer* l_visualizer_object, sf::RenderWindow* l_window)
{
	m_visulaizer = l_visualizer_object;
	window = l_window;
}

void SortManager::BubbleSort()
{
	bool swapped = true;
	int j = 0;
	int temp;

	while (swapped) {
		swapped = false;
		j++;
		for (int i = 0; i < m_visulaizer->getColNum() - j; ++i) {
			if (m_visulaizer->getArray()[i] > m_visulaizer->getArray()[i + 1]) {
				temp = m_visulaizer->getArray()[i];
				m_visulaizer->getArray()[i] = m_visulaizer->getArray()[i + 1];
				m_visulaizer->getArray()[i + 1] = temp;
				swapped = true;

				m_visulaizer->getStupci()[i].changeColour(sf::Color::Green);
				
				UpdateScreen();
				RemoveLimit();
			}
		}
	}
}

//Update Screen
void SortManager::UpdateScreen()
{
	window->clear(sf::Color::Black);

	m_visulaizer->draw(window);
	m_visulaizer->reDraw();

	window->display();
}

void SortManager::RemoveLimit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		window->setFramerateLimit(0);
}

void SortManager::SelectionSort()
{
	for (int i = 0; i < m_visulaizer->getColNum(); i++) {
		int min = i;
		for (int j = i + 1; j < m_visulaizer->getColNum(); j++)
			if (m_visulaizer->getArray()[j] < m_visulaizer->getArray()[min])
			{
				min = j;
				m_visulaizer->getStupci()[i].changeColour(sf::Color::Green);
				m_visulaizer->getStupci()[min].changeColour(sf::Color::Red);
			}
		swap(m_visulaizer->getArray()[min], m_visulaizer->getArray()[i]);
	}
}

void SortManager::swap(int &a, int &b)
{
	int k = a;
	a = b;
	b = k;

	UpdateScreen();
	RemoveLimit();
}

void SortManager::InsertionSort()
{
	int key, j;
	for (int i = 1; i < m_visulaizer->getColNum(); i++)
	{
		key = m_visulaizer->getArray()[i];
		j = i - 1;

		while (j >= 0 && m_visulaizer->getArray()[j] > key)
		{
			m_visulaizer->getArray()[j + 1] = m_visulaizer->getArray()[j];
			j = j - 1;

			m_visulaizer->getStupci()[i].changeColour(sf::Color::Green);
			m_visulaizer->getStupci()[key].changeColour(sf::Color::Red);

			UpdateScreen();
			RemoveLimit();
		}
	m_visulaizer->getArray()[j + 1] = key;
	}
	UpdateScreen();
}
