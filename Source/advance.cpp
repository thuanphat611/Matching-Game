#include <iostream>
#include <fstream>
#include "matching.h"
#include "advance.h"
using namespace std;
void moveSuggestion(char** a) { // ham tao goi y duong di
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 7; j++)
		{
			for (int k = j + 1; k < 7; k++)
				if (a[i][j] == a[i][k] && a[i][j] != ' ')
					if (checkI(a, i, j, i, k) || checkZ(a, i, j, i, k) || checkL(a, i, j, i, k) || checkU(a, i, j, i, k))
					{
						cout << "Move suggestion: " << a[i][j] << "(" << i << "," << j << ") && " << a[i][k] << "(" << i << "," << k << ")";
						return;
					}

			if (i < 5)
			{
				for (int m = i + 1; m < 6; m++)
					for (int n = 1; n < 7; n++)
						if (a[i][j] == a[m][n] && a[i][j] != ' ')
							if (checkI(a, i, j, m, n) || checkZ(a, i, j, m, n) || checkL(a, i, j, m, n) || checkU(a, i, j, m, n))
							{
								cout << "Move suggestion: " << a[i][j] << "(" << i << "," << j << ") && " << a[m][n] << "(" << m << "," << n << ")";
								return;
							}
						
			}
		}
}
void sortfile(string filename) { // ham sap xep cac du lieu cua nguoi choi trong file luu du lieu 
	ifstream in(filename);
	player* a = new player[6];
	int count = 0;
	if (!in)
		return;
	while (!in.eof()) {
		in >> a[count].name;
		in >> a[count].playtime;
		count++;
	}
	in.close();
	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
			if (a[i].playtime > a[j].playtime)
				swap(a[i], a[j]);
	ofstream out(filename);
	if (count >= 5)
		for (int k = 0; k < 5; k++)
			out << a[k].name << " " << a[k].playtime << endl;
	else
		for (int k = 0; k < count; k++)
			out << a[k].name << " " << a[k].playtime << endl;
	out.close();
	delete[] a;
}
void printLB(string filename) { // ham in ra leaderboard
	ifstream in(filename);
	player* a = new player[5];
	int count = 0;
	if (!in)
	{
		cout << "no data" << endl;
		return;
	}
	while (!in.eof()) {
		in >> a[count].name;
		in >> a[count].playtime;
		count++;
	}
	in.close();
	for (int i = 0; i < count - 1; i++)
		cout << a[i].name << ":" << a[i].playtime << "s" << endl;
	delete[] a;
}
void deleteBlank(char** a) { // ham xoa o trong, don sang trai trong difficult mode
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 7; j++)
		{
			if (a[i][j] == ' ')
			{
				for (int l = j; l < 6; l++)
				{
					a[i][l] = a[i][l + 1];
					a[i][l + 1] = ' ';
				}
			}
			if (a[i][j] == ' ')
			{
				for (int l = j; l < 6; l++)
				{
					a[i][l] = a[i][l + 1];
					a[i][l + 1] = ' ';
				} 
			}
		}
}