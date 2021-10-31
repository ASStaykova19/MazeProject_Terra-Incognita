#include <iostream>
#include <windows.h>
#include<ctime>

using namespace std;

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