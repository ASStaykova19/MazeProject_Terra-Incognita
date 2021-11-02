#include <iostream>
#include <vector>
#include <windows.h>
#include<ctime>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

struct CELL {
	bool left;
	bool top;
	bool right;
	bool bottom;
	bool visited;
	char symbol;
};

void showMaze(CELL** map, int size)
{
	system("cls");

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size * 2; j++)
		{
			if (map[i][j].symbol == '*')
			{
				SetConsoleTextAttribute(hConsole, 6);
				cout << map[i][j].symbol;
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				cout << map[i][j].symbol;
			}
		}
		cout << endl;
	}

	cout << endl;
}

CELL** gemazeGenerator(CELL** map, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			map[i][j].symbol = '#';
			map[i][j].left = true;
			map[i][j].top = true;
			map[i][j].right = true;
			map[i][j].bottom = true;
			map[i][j].visited = false;
		}
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			map[1][j].top = false;
			map[size - 2][j].bottom = false;
			map[i][1].left = false;
			map[i][size - 2].right = false;
		}
	}

	srand((unsigned)time(NULL));

	int random = 0;

	int ranX = 0;
	int ranY = 0;

	ranX = (2 * rand()) % (size - 1);
	ranY = (2 * rand()) % (size - 1);

	int visitedCells = 1;
	int totalCells = ((size - 1) / 2) * ((size - 1) / 2);

	vector<int> backX, backY;

	map[ranY][ranX].symbol = 'J';
	map[ranY][ranX].visited = true;

	int ranYmin = ranY - 2;
	int ranYplus = ranY + 2;
	int ranXmin = ranX - 2;
	int ranXplus = ranX + 2;

	if (ranYmin < 0)
	{
		ranYmin = 0;
	}
	if (ranYplus > size - 2)
	{
		ranYplus = size - 2;
	}
	if (ranXmin < 0)
	{
		ranXmin = 0;
	}
	if (ranXplus > size - 2)
	{
		ranXplus = size - 2;
	}

	while (visitedCells < totalCells)
	{
		if (((map[ranYmin][ranX].visited == false) && (map[ranY][ranX].top == true && map[ranYmin][ranX].bottom == true)) ||
			((map[ranYplus][ranX].visited == false) && (map[ranY][ranX].top == true && map[ranYplus][ranX].bottom == true)) ||
			((map[ranY][ranXmin].visited == false) && (map[ranY][ranX].left == true && map[ranY][ranXmin].right == true)) ||
			((map[ranY][ranXplus].visited == false) && (map[ranY][ranX].left == true && map[ranY][ranXplus].right == true)))
		{
			random = (rand() % 4) + 1;

			if ((random == 1) && (ranY > 1))
			{
				if (map[ranY - 2][ranX].visited == false)
				{
					map[ranY - 1][ranX].symbol = ' ';
					map[ranY - 1][ranX].visited = true;
					map[ranY][ranX].top = false;

					backX.push_back(ranX);
					backY.push_back(ranY);

					ranY -= 2;
					map[ranY][ranX].visited = true;
					map[ranY][ranX].symbol = ' ';
					map[ranY][ranX].bottom = false;
					visitedCells++;
				}
				else
				{
					continue;
				}
			}
			else if ((random == 2) && (ranY < size - 2))
			{
				if (map[ranY + 2][ranX].visited == false)
				{
					map[ranY + 1][ranX].symbol = ' ';
					map[ranY + 1][ranX].visited = true;
					map[ranY][ranX].bottom = false;

					backX.push_back(ranX);
					backY.push_back(ranY);

					ranY += 2;
					map[ranY][ranX].visited = true;
					map[ranY][ranX].symbol = ' ';
					map[ranY][ranX].top = false;
					visitedCells++;
				}
				else
				{
					continue;
				}
			}
			else if ((random == 3) && (ranX > 1))
			{
				if (map[ranY][ranX - 2].visited == false)
				{
					map[ranY][ranX - 1].symbol = ' ';
					map[ranY][ranX - 1].visited = true;
					map[ranY][ranX].left = false;

					backX.push_back(ranX);
					backY.push_back(ranY);

					ranX -= 2;
					map[ranY][ranX].visited = true;
					map[ranY][ranX].symbol = ' ';
					map[ranY][ranX].right = false;
					visitedCells++;
				}
				else
				{
					continue;
				}
			}
			else if ((random == 4) && (ranX < size - 2))
			{
				if (map[ranY][ranX + 2].visited == false)
				{
					map[ranY][ranX + 1].symbol = ' ';
					map[ranY][ranX + 1].visited = true;
					map[ranY][ranX].right = false;

					backX.push_back(ranX);
					backY.push_back(ranY);

					ranX -= 2;
					map[ranY][ranX].visited = true;
					map[ranY][ranX].symbol = ' ';
					map[ranY][ranX].left = false;
					visitedCells++;
				}
				else
				{
					continue;
				}
			}
		}
		else {
			ranX = backX.back();
			backX.pop_back();

			ranY = backY.back();
			backY.pop_back();
		}

		showMaze(map, size);
		int d;
		cin >> d;
	}


	return map;
}