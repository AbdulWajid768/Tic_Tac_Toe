#include<iostream>
#include"function.h"
using namespace std;
void display(char a[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int inputPlayer1(char a[3][3])
{
	int x, check = 0;
	while (check == 0)
	{
		cout << "Enter Input Player 1 : ";
		cin >> x;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (a[i][j] == char(x + 48))
				{
					if (a[i][j] != 'X' && a[i][j] != 'Y')
					{
						a[i][j] = 'X';
						check = check + 1;
					}
				}
			}
		}

	}
	return x;
}
int inputPlayer2(char a[3][3])
{
	int y, check = 0;
	while (check == 0)
	{
		cout << "Enter Input Player 2 : ";
		cin >> y;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (a[i][j] == char(y + 48))
				{
					if (a[i][j] != 'X' && a[i][j] != 'Y')
					{
						a[i][j] = 'Y';
						check = check + 1;
					}
				}
			}
		}

	}
	return y;
}
//void put(int x, int y, char a[3][3])
//{
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			if (a[i][j] == char(x + 48))
//			{
//				a[i][j] = 'X';
//			}
//			if (a[i][j] == char(y + 48))
//			{
//				a[i][j] = 'Y';
//			}
//		}
//	}
//}
int winPlayer(char a[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (a[0][i] == a[1][i] && a[1][i] == a[2][i])
		{
			if (a[0][i] == 'X')
			{
				return 2;
			}
			if (a[0][i] == 'Y')
			{
				return 3;
			}
		}
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2])
		{
			if (a[i][0] == 'X')
			{
				return 2;
			}
			if (a[i][0] == 'Y')
			{
				return 3;
			}
		}
	}
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
	{
		if (a[0][0] == 'X')
		{
			return 2;
		}
		if (a[0][0] == 'Y')
		{
			return 3;
		}
	}
	if (a[2][0] == a[1][1] && a[1][1] == a[0][2])
	{
		if (a[2][0] == 'X')
		{
			return 2;
		}
		if (a[2][0] == 'Y')
		{
			return 3;
		}
	}
	return 1;
}
void winDeclare(int x)
{
	if (x == 2)
	{
		cout << "PLAYER 1 : WINS" << endl;
		exit(0);
	}
	if (x == 3)
	{
		cout << "PLAYER 2 : WINS" << endl;
		exit(0);
	}
}
void myMain()
{
	char a[3][3] = { 49,50,51,52,53,54,55,56,57 };
	int x, y;
	int win = 1, loop = 0;
	display(a);
	x = inputPlayer1(a);
	display(a);
	while (loop <= 4 && win == 1)
	{
		loop++;
		y = inputPlayer2(a);
		display(a);
		win = winPlayer(a);
		winDeclare(win);
		x = inputPlayer1(a);
		display(a);
		win = winPlayer(a);
		winDeclare(win);
	}
	if (loop == 4)
	{
		cout << "DRAWN" << endl;
	}
}