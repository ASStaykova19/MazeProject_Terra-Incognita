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