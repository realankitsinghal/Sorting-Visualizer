#include "game.h"


char Choice()
{
	int sort;
	printf("SPACE = START\nLALT = No FPS Limit\n\n\nChoose sorting algorithm!\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\nChoice: ");
	scanf_s("%d", &sort);

	return sort;
}

int main()
{
	int curSort = Choice();

	Game game(sf::Vector2u(1280, 720), "Sorting Visualised");

	while (!game.getWindow() -> IsDone())
	{
		if (game.HandleInput())
			switch (curSort)
			{
			case 1: game.getSortManager()->BubbleSort(); break;
			case 2: game.getSortManager()->SelectionSort(); break;
			case 3: game.getSortManager()->InsertionSort(); break;
			}

		game.Update();
		game.Render();
		game.RestartClock();
	}

	return 0;
}