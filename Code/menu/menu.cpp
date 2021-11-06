#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void menu()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	string sentances[2] = { "Begin Game" , "How to Play?" };
	int arrow = 0;

	bool choose = true;

	while (choose)
	{
		SetConsoleTextAttribute(hConsole, 5);

		cout << "             _______   _         _______   _______   _______   _______       _________  _______" << endl;
		cout << " |\\     /| (   ____ \\ ( \\       (  ____ \\ (  ___  ) (       ) (  ____ \\      \\__  __/  (  ___  )" << endl;
		cout << " | )   ( | |  (    \\/ | (       | (    \\/ | (   ) | | () () | | (    \\/         ) (    | (   ) |" << endl;
		cout << " | | _ | | |  (__     | |       | |       | |   | | | || || | | (__             | |    | |   | |" << endl;
		cout << " | |( )| | |   __)    | |       | |       | |   | | | |(_)| | |  __)            | |    | |   | |" << endl;
		cout << " | || || | |  (       | |       | |       | |   | | | |   | | | (               | |    | |   | |" << endl;
		cout << " | () () | |  (____/\\ | (____/\\ | (____/\\ | (___) | | )   ( | | (____/\\         | |    | (___) |" << endl;
		cout << " (_______) (________/ (_______/ (_______/ (_______) |/     \\| (_______/         )_(    (_______)" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "     _________            _______          _______   _______   _______   _______    _" << endl;
		cout << "     \\__   __/ |\\     /| (  ____ \\        (       ) (  ___  ) / ___   ) (  ____ \\  ( )" << endl;
		cout << "        ) (    | )   ( | | (    \\/        | () () | | (   ) | \\/   )  | | (    \\/  | |" << endl;
		cout << "        | |    | (___) | | (__            | || || | | (___) |     /   / | (__      | |" << endl;
		cout << "        | |    |  ___  | |  __)           | |(_)| | |  ___  |    /   /  |  __)     | |" << endl;
		cout << "        | |    | (   ) | | (              | |   | | | (   ) |   /   /   | (        (_)" << endl;
		cout << "        | |    | )   ( | | (____/\\        | )   ( | | )   ( |  /   (_/\\ | (____/\\   _" << endl;
		cout << "        )_(    |/     \\| (_______/        |/     \\| |/     \\| (_______/ (_______/  (_)" << endl;
		cout << "" << endl;
		cout << "" << endl;

		SetConsoleTextAttribute(hConsole, 8);

		cout << " Use the UP and DOWN arrows to move and Space to select:" << endl;
		cout << "" << endl;

		if (arrow == 0)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << " -->" << '\t' << sentances[0] << "\t<--" << endl;
			cout << '\t' << sentances[1] << endl;
		}

		SetConsoleTextAttribute(hConsole, 8);

		if (arrow == 1)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << '\t' << sentances[0] << endl;
			cout << " -->" << '\t' << sentances[1] << "\t<--" << endl;
		}

		system("pause>nul");

		if (GetAsyncKeyState(VK_UP))
		{
			if (arrow == 0)
			{
				Sleep(0);
			}
			else
			{
				arrow--;
			}
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (arrow == 1)
			{
				Sleep(0);
			}
			else
			{
				arrow++;
			}
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (arrow == 0)
			{
				choose = false;
			}
			else
			{
				system("cls");
				SetConsoleTextAttribute(hConsole, 7);
				cout << endl;
				cout << " Here's how you can play this maze:\n\n";
				SetConsoleTextAttribute(hConsole, 5);
				cout << " * When you choose the option 'Begin Game' you have to enter map height and width\n";

				cout << " * You can move your character by using the UP, DOWN, LEFT and RIGHT arrows\n";

				cout << " * Collect the collectables (*) to earn extra points\n";

				cout << " * After you reach the end of the maze you'll have to choose if you want to play again or not\n\n";
				SetConsoleTextAttribute(hConsole, 7);
				cout << " Press any button to return to the menu";
				system("pause>nul");


			}
		}
		system("cls");
	}
}