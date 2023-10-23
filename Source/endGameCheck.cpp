#include <iostream>
#include "endGameCheck.h"
#include "matching.h"
bool checkPairsLeft(char **a) { // ham kiem tra xem bang con o nao khong
	for (int i = 1; i < 6; i++)
		for (int j = 0; j < 7; j++)
			if (a[i][j] != ' ')
				return true;
	return false;
}
bool checkValidPairs(char **a) { // ham kiem tra xem con o nao noi duoc voi nhau khong
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 7; j++)
		{
			for (int k = j + 1; k < 7; k++)
				if (a[i][j] == a[i][k] && a[i][j] != ' ')
					if (checkI(a, i, j, i, k) || checkL(a, i, j, i, k) || checkZ(a, i, j, i, k) || checkU(a, i, j, i, k))
					{
						return true;
					}
			if (i < 5)
			{
				for (int m = i + 1; m < 6; m++)
					for (int n = 1; n < 7; n++)
						if (a[i][j] == a[m][n] && a[i][j] != ' ')
							if (checkI(a, i, j, m, n) || checkL(a, i, j, m, n) || checkZ(a, i, j, m, n) || checkU(a, i, j, m, n))
							{
								return true;
							}
			}
		}	
	return false;
}