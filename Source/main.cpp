#include <iostream>
#include <fstream>
#include <conio.h>
#include "board.h"
#include "matching.h"
#include "endGameCheck.h"
#include <string>
#include "advance.h"
#include "boardLinkedList.h"
using namespace std;
int main() {
	char  ** a;
	int sx = 1, sy = 1; // o de nguoi dung dieu khien;
	int x1, y1, x2, y2, count;// 2 o duoc nguoi dung chon, bien count de dem xem nguoi dung da chon bao nhieu o
	int tmp = 0;
	int menuPointer = 1; // bien de dieu khien game menu
	reset(count, x1, y1, x2, y2);
	clock_t start, end;
	player Player;
	char command, menuCommand, gameCommand;
	
	do {
		do {
			system("cls");
			printMenu(menuPointer);
			menuCommand = _getch();
			if (menuCommand != 13)
				move(4, 0, menuPointer, tmp, menuCommand);
			if (int(menuCommand) == 13 && menuPointer == 3)
			{
				system("cls");
				cout << "Leaderboard" << endl;
				cout << "Easy mode:" << endl;
				printLB("Easy.txt");
				cout << "Difficult mode:" << endl;
				printLB("difficult.txt");
				system("pause");
			}
			if (int(menuCommand) == 13 && menuPointer == 4)
			{
				gameCommand = 27;
				break;
			}
		} while ((int(menuCommand) != 13 || (menuPointer != 1 && menuPointer != 2)));
		if (menuPointer == 1)
		{
			system("cls");
			cout << "please enter your name: ";
			cin >> Player.name;
			start = clock();
			a = genBoard();
			do {
				system("cls");
				repBoard(a, 7, 8, sx, sy, x1, y1, x2, y2);
				command = _getch();
				if (int(command) == 13)
				{
					if (count == 0 && a[sx][sy] != ' ') 
					{
						x1 = sx;
						y1 = sy;
						count = 1;
					}
					if (count == 1 && (sx != x1 || sy != y1) && a[sx][sy] != ' ')
					{
						x2 = sx;
						y2 = sy;
						count = 2;
					}
				}
				if (count == 2) {
					if (checkI(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]))
					{
						deletecell(a[x1][y1], a[x2][y2]);
						reset(count, x1, y1, x2, y2);
					}
					if (checkZ(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]))
					{
						deletecell(a[x1][y1], a[x2][y2]);
						reset(count, x1, y1, x2, y2);
					}
					if (checkL(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]))
					{
						deletecell(a[x1][y1], a[x2][y2]);
						reset(count, x1, y1, x2, y2);
					}
					if (checkU(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]))
					{
						deletecell(a[x1][y1], a[x2][y2]);
						reset(count, x1, y1, x2, y2);
					}
					if (!checkI(a, x1, y1, x2, y2) || !checkL(a, x1, y1, x2, y2) || !checkZ(a, x1, y1, x2, y2) || checkU(a, x1, y1, x2, y2) || (a[x1][y1] != a[x2][y2]))
						reset(count, x1, y1, x2, y2);
				}
				if (int(command) != 13)
					move(5, 6, sx, sy, command);
				if (command == 'h') {
					moveSuggestion(a);
					cout << endl;
					system("pause");
				}
			} while (checkPairsLeft(a) && checkValidPairs(a));
			end = clock();
			Player.playtime = (end - start) / CLOCKS_PER_SEC;
			system("cls");
			if (checkPairsLeft(a))
			{
				cout << "Game over due to no valid pairs left" << endl;
			}
			if (!checkPairsLeft(a))
			{
				cout << "You win!" << endl;
				cout << "playtime : " << Player.playtime << "s" << endl;
				fstream out("easy.txt", ios::out | ios::app);
				out << Player.name << " " << Player.playtime;
				out.close();
				sortfile("easy.txt");
			}
		}
		if (menuPointer == 2)
		{
			system("cls");
			a = genBoard();
			cout << "please enter your name: ";
			cin >> Player.name;
			start = clock();
			do {
				system("cls");
				repBoard(a, 7, 8, sx, sy, x1, y1, x2, y2);
				command = _getch();
				if (int(command) == 13)
				{
					if (count == 0 && a[sx][sy] != ' ')
					{
						x1 = sx;
						y1 = sy;
						count = 1;
					}
					if (count == 1 && (sx != x1 || sy != y1) && a[sx][sy] != ' ')
					{
						x2 = sx;
						y2 = sy;
						count = 2;
					}
				}
				if (count == 2) {
					if (checkI(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]))
					{
						deletecell(a[x1][y1], a[x2][y2]);
						reset(count, x1, y1, x2, y2);
					}
					if (checkZ(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]))
					{
						deletecell(a[x1][y1], a[x2][y2]);
						reset(count, x1, y1, x2, y2);
					}
					if (checkL(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]))
					{
						deletecell(a[x1][y1], a[x2][y2]);
						reset(count, x1, y1, x2, y2);
					}
					if (checkU(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]))
					{
						deletecell(a[x1][y1], a[x2][y2]);
						reset(count, x1, y1, x2, y2);
					}
					if (!checkI(a, x1, y1, x2, y2) || !checkL(a, x1, y1, x2, y2) || !checkZ(a, x1, y1, x2, y2) || checkU(a, x1, y1, x2, y2) || (a[x1][y1] != a[x2][y2]))
						reset(count, x1, y1, x2, y2);
				}
				if (int(command) != 13)
					move(5, 6, sx, sy, command);
				if (command == 'h') {
					moveSuggestion(a);
					cout << endl;
					system("pause");
				}
				deleteBlank(a);
			} while (checkPairsLeft(a) && checkValidPairs(a));
			end = clock();
			Player.playtime = (end - start) / CLOCKS_PER_SEC;
			system("cls");
			if (checkPairsLeft(a))
			{
				cout << "Game over due to no valid pairs left." << endl;
			}
			if (!checkPairsLeft(a))
			{
				cout << "You win!" << endl;
				cout << "playtime : " << Player.playtime << "s" << endl;
				fstream out("difficult.txt", ios::out | ios::app);
				out << Player.name << " " << Player.playtime;
				out.close();
				sortfile("difficult.txt");
			}
		}
		if (menuPointer != 4)
		{
			cout << "press ESC to exit" << endl;
			cout << "press any key to return to menu." << endl;
			gameCommand = _getch();
		}
	} while (int(gameCommand) != 27);
	system("cls");
	cout << "you exited the game.";
	return 0;
}
