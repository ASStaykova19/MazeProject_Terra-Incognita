#include <iostream>
#include <windows.h>
#include<ctime>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

char** mazeGenerator(char** map, int size)
{
	srand(int(time(0)));

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size * 2; j++)
		{
			if (rand() % 2 == 0)
			{
				map[i][j] = ' ';
			}
			else
			{
				map[i][j] = '#';
			}
		}
	}

	map[size - 2][size * 2 - 2] = 'X';


	for (int i = 0; i < size; i++)
	{
		map[i][0] = '#';
	}
	for (int i = 0; i < size; i++)
	{
		map[i][(size * 2) - 1] = '#';
	}
	for (int i = 0; i < size * 2; i++)
	{
		map[0][i] = '#';
	}
	for (int i = 0; i < size * 2; i++)
	{
		map[size - 1][i] = '#';
	}

	return map;
}

void showMaze(char** map, int size)
{
	system("cls");

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size * 2; j++)
		{
			if (map[i][j] == '*')
			{
				SetConsoleTextAttribute(hConsole, 6);
				cout << map[i][j];
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				cout << map[i][j];
			}
		}
		cout << endl;
	}

	cout << endl;
}