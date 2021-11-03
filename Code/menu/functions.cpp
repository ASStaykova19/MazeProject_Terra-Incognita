#include <iostream>
#include <vector>
#include <windows.h>
#include<ctime>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#define WALL_UP 0
#define WALL_RIGHT 1
#define WALL_DOWN 2
#define WALL_LEFT 3

int mapHeight = 0;
int mapWidth = 0;

int indexXY(int x, int y)
{
	return y * mapWidth + x;
}

bool checkXY(int x, int y)
{
	if (x < 0 || x >= mapWidth) return false;
	if (y < 0 || y >= mapHeight) return false;

	return true;
}

void generateMap(int x, int y, char* grid)
{
	grid[indexXY(x, y)] = ' ';

	int dirs[4];
	dirs[0] = WALL_UP;
	dirs[1] = WALL_RIGHT;
	dirs[2] = WALL_DOWN;
	dirs[3] = WALL_LEFT;

	for (int i = 0; i < 4; ++i)
	{
		int r = rand() & 3;
		int temp = dirs[r];
		dirs[r] = dirs[i];
		dirs[i] = temp;
	}

	for (int i = 0; i < 4; ++i)
	{
		int dx = 0, dy = 0;

		switch (dirs[i])
		{
		case WALL_UP: dy = -1; break;
		case WALL_DOWN: dy = 1; break;
		case WALL_RIGHT: dx = 1; break;
		case WALL_LEFT: dx = -1; break;
		}

		int x2 = x + (dx << 1);
		int y2 = y + (dy << 1);

		if (checkXY(x2, y2))
		{
			if (grid[indexXY(x2, y2)] == '#')
			{
				grid[indexXY(x2 - dx, y2 - dy)] = ' ';

				generateMap(x2, y2, grid);
			}
		}
	}
}