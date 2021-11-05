#include "functions.h"

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int colectCount = 0;
	int playerColect = 0;

	int x = 1;
	int y = 1;

	char* grid = new char[mapHeight * mapWidth];

	char** map = new char* [mapHeight * mapWidth];

	for (int i = 0; i < mapHeight; i++)
	{
		map[i] = new char[mapWidth];
	}

	for (int i = 0; i < mapWidth * mapHeight; i++)
	{
		grid[i] = '#';
	}

    menu();
}