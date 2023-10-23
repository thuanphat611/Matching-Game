#include "board.h"
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
void set_color(int code) { //ham doi mau nen va mau chu 
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}
void repBoard(char **a, int m, int n, int px, int py, int x1, int y1, int x2, int y2) { // ham ve bang ra console

	cout << " ";
	for (int j = 1; j < n - 1; j++)
		cout << "    " << j << "    ";
	cout << endl << " ";
	for (int i = 1; i < m - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (a[i][j] != ' ')
			{
				repColor(a[i][j]);
				cout << " ------- ";
			}
			if (a[i][j] == ' ')
				cout << "         ";
		}
		cout << endl << " ";
		for (int j = 1; j < n - 1; j++)
		{
			if (a[i][j] != ' ')
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					repColor(a[i][j]);
					cout << "|";
					set_color(0x70);
					cout << "       ";
					repColor(a[i][j]);
					cout << "|";
				}
				else
				{
					repColor(a[i][j]);
					cout << "|       |";
				}
			}
			else
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					cout << " ";
					set_color(0x70);
					cout << "       ";
					set_color(0x07);
					cout << " ";
				}
				else
					cout << "         ";
			}
		}
		cout << endl;
		for (int j = 1; j < n - 1; j++)
		{
			if (j == 1)
			{
				set_color(0x07);
				cout << i;
			}
			if (a[i][j] != ' ')
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					repColor(a[i][j]);
					cout << "|";
					set_color(0x70);
					cout << "   " << a[i][j] << "   ";
					repColor(a[i][j]);
					cout << "|";
				}
				else
				{
					repColor(a[i][j]);
					cout << "|   "<< a[i][j] << "   |";
				}
			}
			else
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					cout << " ";
					set_color(0x70);
					cout << "       ";
					set_color(0x07);
					cout << " ";
				}
				else
					cout << "         ";
			}
		}
		cout << endl << " ";
		for (int j = 1; j < n - 1; j++)
		{
			if (a[i][j] != ' ')
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					repColor(a[i][j]);
					cout << "|";
					set_color(0x70);
					cout << "       ";
					repColor(a[i][j]);
					cout << "|";
				}
				else
				{
					repColor(a[i][j]);
					cout << "|       |";
				}
			}
			else
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					cout << " ";
					set_color(0x70);
					cout << "       ";
					set_color(0x07);
					cout << " ";
				}
				else
					cout << "         ";
			}
		}
		cout << endl << " ";
		for (int j = 1; j < n - 1; j++)
		{
			if (a[i][j] != ' ')
			{
				repColor(a[i][j]);
				cout << " ------- ";
			}
			if (a[i][j] == ' ')
				cout << "         ";
		}
		cout << endl << " ";
		set_color(0x07);
	}
}
char** genBoard() {// ham tao gia tri cho cac o của bang
	srand(time(0));
	char** a;
	a = new char* [7];
	for (int t = 0; t < 7; t++)
		a[t] = new char[8];
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 8; j++)
			a[i][j] = ' ';
	int rd[8] = { 4,4,4,4,4,4,4,2 }; // mang quy dinh so lan xuat hien cua cac chu cai tu A toi H, o day chi co 4+4+4+4+4+4+4+2 = 30 o
	int random;
	random = rand() % 8;
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 7; j++)
		{
			while (rd[random] == 0)
				random = rand() % 8;
			a[i][j] = 'A' + random;
			rd[random]--;
			random = rand() % 8;
		}
	return a;
}
void repColor(char c) {// ham bieu dien mau tuy vao o
	switch (c)
	{
	case 'A': 
	{
		set_color(0x01);
		break;
	}
	case 'B':
	{
		set_color(0x02);
		break;
	}
	case 'C': 
	{
		set_color(0x0E);
		break;
	}
	case 'D': 
	{
		set_color(0x04);
		break;
	}
	case 'E': 
	{
		set_color(0x05);
		break;
	}
	case 'F':
	{
		set_color(0x06);
		break;
	}
	case 'G':
	{
		set_color(0x0B);
		break; 
	}
	case 'H': 
	{
			set_color(0x0C);
			break;
	}
	};
}
void deletecell(char& a, char& b) { // ham xoa o nhap vao
	a = ' ';
	b = ' ';
}
void  printMenu(int menuPointer) { // ham in menu ra console
	cout << "Game menu:" << endl;
	if (menuPointer == 1)
		cout << ">Easy mode" << endl;
	else
		cout << "Easy mode" << endl;
	if (menuPointer == 2)
		cout << ">Difficult mode" << endl;
	else
		cout << "Difficult mode" << endl;
	if (menuPointer == 3)
		cout << ">Leaderboard" << endl;
	else
		cout << "Leaderboard" << endl;
	if (menuPointer == 4)
		cout << ">Exit game";
	else
		cout << "Exit game";

}
