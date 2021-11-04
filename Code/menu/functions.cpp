#include <iostream>
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

int colectCount = 0;
int playerColect = 0;

int x = 1;
int y = 1;

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

char** transfer(char** map, char* grid, int& colectCount)
{
	system("cls");

	for (int y = 0; y < mapHeight; ++y)
	{
		for (int x = 0; x < mapWidth; ++x)
		{
			map[y][x] = grid[indexXY(x, y)];

			int random = rand();

			if (map[y][x] == ' ')
			{
				if (random % 51 == 0 && (map[y][x] != map[1][1] || map[y][x] != map[mapHeight - 2][mapWidth - 2]))
				{
					map[y][x] = '*';
					colectCount++;
				}
			}
		}
	}

	return map;
}

void makeExit(char** map)
{
	bool exisIsMade = false;
	for (int i = 1; i < mapHeight; i++)
	{
		for (int j = 1; j < mapWidth; j++)
		{
			if (map[i][j] != map[1][1])
			{
				if ((map[i][j - 1] == '#' && map[i - 1][j - 1] == '#') && (map[i - 1][j] == '#' && map[i - 1][j + 1] == '#') && map[i][j + 1] == '#')
				{
					map[i][j] = 'x';
					exisIsMade = true;
					break;
				}
				else if ((map[i - 1][j] == '#' && map[i - 1][j + 1] == '#') && (map[i][j + 1] == '#' && map[i + 1][j + 1] == '#') && map[i + 1][j] == '#')
				{
					map[i][j] = 'x';
					exisIsMade = true;
					break;
				}
				else if ((map[i][j + 1] == '#' && map[i + 1][j + 1] == '#') && (map[i + 1][j] == '#' && map[i + 1][j - 1] == '#') && map[i][j - 1] == '#')
				{
					map[i][j] = 'x';
					exisIsMade = true;
					break;
				}
				else if ((map[i - 1][j] == '#' && map[i - 1][j - 1] == '#') && (map[i][j - 1] == '#' && map[i + 1][j - 1] == '#') && map[i + 1][j] == '#')
				{
					map[i][j] = 'x';
					exisIsMade = true;
					break;
				}
			}
		}
		if (exisIsMade)
		{
			break;
		}
	}
}

void drawMap(char** map)
{
	system("cls");

	for (int y = 0; y < mapHeight; ++y)
	{
		for (int x = 0; x < mapWidth; ++x)
		{
			if (map[y][x] == 'J')
			{
				SetConsoleTextAttribute(hConsole, 4);
				cout << " " << map[y][x];
				SetConsoleTextAttribute(hConsole, 7);
			}
			else if (map[y][x] == 'x')
			{
				SetConsoleTextAttribute(hConsole, 2);
				cout << " " << map[y][x];
				SetConsoleTextAttribute(hConsole, 7);
			}
			else if (map[y][x] == '*')
			{
				SetConsoleTextAttribute(hConsole, 6);
				cout << " " << map[y][x];
				SetConsoleTextAttribute(hConsole, 7);
			}
			else
			{
				if ((y + x) % 2 == 0)
				{
					SetConsoleTextAttribute(hConsole, 8);
					cout << " " << map[y][x];
					SetConsoleTextAttribute(hConsole, 7);
				}
				else
				{
					cout << " " << map[y][x];
				}
			}
		}

		cout << endl;
	}
}

void move(char** map)
{
	bool gameRuning = true;

	while (gameRuning == true)
	{
		drawMap(map);

		cout << endl;

		if (playerColect == colectCount)
		{
			SetConsoleTextAttribute(hConsole, 5);
			cout << "Colected: " << playerColect << " of " << colectCount;
		}
		else
		{
			cout << "Colected: " << playerColect << " of " << colectCount;
		}

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN))
		{
			int y2 = y + 1;
			if (map[y2][x] == ' ')
			{
				map[y][x] = ' ';
				y++;
				map[y][x] = 'J';
			}
			if (map[y2][x] == '*')
			{
				playerColect++;
				map[y][x] = ' ';
				y++;
				map[y][x] = 'J';
			}
			if (map[y2][x] == 'x')
			{
				system("cls");
				SetConsoleTextAttribute(hConsole, 2);
				cout << "YOU WIN";
				gameRuning = false;
			}
		}
		if (GetAsyncKeyState(VK_UP))
		{
			int y2 = y - 1;
			if (map[y2][x] == ' ')
			{
				map[y][x] = ' ';
				y--;
				map[y][x] = 'J';
			}
			if (map[y2][x] == '*')
			{
				playerColect++;
				map[y][x] = ' ';
				y--;
				map[y][x] = 'J';
			}
			if (map[y2][x] == 'x')
			{
				system("cls");
				SetConsoleTextAttribute(hConsole, 2);
				cout << "YOU WIN";
				gameRuning = false;
			}
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			int x2 = x + 1;
			if (map[y][x2] == ' ')
			{
				map[y][x] = ' ';
				x++;
				map[y][x] = 'J';
			}
			if (map[y][x2] == '*')
			{
				playerColect++;
				map[y][x] = ' ';
				x++;
				map[y][x] = 'J';
			}
			if (map[y][x2] == 'x')
			{
				system("cls");
				SetConsoleTextAttribute(hConsole, 2);
				cout << "YOU WIN";
				gameRuning = false;
			}
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			int x2 = x - 1;
			if (map[y][x2] == ' ')
			{
				map[y][x] = ' ';
				x--;
				map[y][x] = 'J';
			}
			if (map[y][x2] == '*')
			{
				playerColect++;
				map[y][x] = ' ';
				x--;
				map[y][x] = 'J';
			}
			if (map[y][x2] == 'x')
			{
				system("cls");
				SetConsoleTextAttribute(hConsole, 2);
				cout << "YOU WIN";
				gameRuning = false;
			}
		}

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, 4);
			cout << "GAME OVER";
			gameRuning = false;
		}
	}
}

void enterSize()
{
	cin >> mapHeight;
	cin >> mapWidth;
}