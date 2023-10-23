#include <iostream>
#include  "matching.h"
using namespace std;
bool checkline(char **a, int start, int end, int row) // ham kiem tra xem 1 hang co phai la hang "trong"
{ 
	for (int i = start; i <= end; i++)
		if (a[row][i] != ' ')
			return false;
	return true; 
}
bool checkcolumn(char **a, int start, int end, int column) // ham kiem tra xem 1 cot co phai la cot "trong"
{
	for (int i = start; i <= end; i++)
		if (a[i][column] != ' ') 
			return false;
	return true; 
}
void move(int xMax, int yMax, int& sx, int& sy, char command) { // ham di chuyen o con tro dua vao nut nguoi dung nhap la a,s,w hay d
	switch (command) {
	case 'd': { // di chuyen o con tro sang phai
		if (sy < yMax) // neu chua vuot qua bien thi di chuyen thanh cong
			sy++;
		break;
	}
	case 'a': { // di chuyen o con tro sang trai
		if (sy > 1) // neu chua vuot qua bien thi di chuyen thanh cong
			sy--;
		break;
	}
	case 's': { // di chuyen o con tro xuong duoi
		if (sx < xMax)// neu chua vuot qua bien thi di chuyen thanh cong
			sx++;
		break;
	}
	case 'w': { // di chuyen o con tro len tren
		if (sx > 1)// neu chua vuot qua bien thi di chuyen thanh cong
			sx--;
		break;
	}
	}
}
bool checkI(char **a, int x1, int y1, int x2, int y2) { // ham kiem tra 2 o co noi kieu I duoc hay khong
	if (x1 == x2 && y1 == y2)
		return false;
	if (x1 == x2) 
	{
		int Min = min(y1, y2)+1; 
		int Max = max(y1, y2)-1;
		return checkline(a, Min, Max, x1);
	}
	else if (y1 == y2)  
	{
		int Min = min(x1, x2) + 1;
		int Max = max(x1, x2) - 1;
		return checkcolumn(a, Min, Max, y1);
	}
	return false;
}
bool checkL(char **a, int x1, int y1, int x2, int y2) { // ham kiem tra xem 2 o co noi kieu L duoc khong
	if (x1 == x2 || y1 == y2) //neu 2 o cung hang hoac cung cot thi khong noi kieu L duoc
		return false;
	// kiem tra kieu phan bo cua 2 o, co 2 kieu phan bo
	if ((y1 < y2 && x1 < x2) || (y1 > y2 && x1 > x2)) // kieu thu 1: 1 o nam ben trai phia tren(Left Up) va 1 o nam ben phai phia duoi(Right Down)
	{												
		int LUx, LUy, RDx, RDy;
		if (y1 < y2 && x1 < x2) // xac dinh o nao la Left Up, o nao la Right Down
		{
			LUx = x1;
			LUy = y1;
			RDx = x2;
			RDy = y2;
		}
		if (y1 > y2 && x1 > x2) 
		{
			LUx = x2;
			LUy = y2;
			RDx = x1;
			RDy = y1;
		}
		if (checkline(a, LUy + 1, RDy, LUx) && checkcolumn(a, LUx, RDx -1, RDy)) 
			return true;
		if (checkline(a, LUy, RDy - 1, RDx) && checkcolumn(a, LUx + 1, RDx, LUy))
			return true;
		return false;
	}
	if ((y1 > y2 && x1 < x2) || (y1 < y2 && x1 > x2))// kieu thu 2: mot o nam phi tren ben phai(Right Up) va mot o nam phia duoi ben trai(Left Down)
	{
		int RUx, RUy, LDx, LDy;
		if (y1 > y2 && x1 < x2) // xac dinh o nao la Right Up, o nao la Left Down
		{
			RUx = x1;
			RUy = y1;
			LDx = x2;
			LDy = y2;
		}
		if (y1 < y2 && x1 > x2) 
		{
			RUx = x2;
			RUy = y2;
			LDx = x1;
			LDy = y1;
		}

		if (checkline(a, LDy, RUy - 1, RUx) && checkcolumn(a, RUx, LDx - 1, LDy))
			return true;
		if (checkline(a, LDy + 1, RUy, LDx) && checkcolumn(a, RUx + 1, LDx, RUy))
			return true;
		return false;
	}
}
bool checkZ(char **a, int x1, int y1, int x2, int y2) {
	if (x1 == x2 || y1 == y2) //neu 2 o cung hang hoac cung cot thi khong noi kieu Z duoc
		return false;
	if ((y1 < y2 && x1 < x2) || (y1 > y2 && x1 > x2))//kiem tra kieu phan bo cua 2 o tuong tu ham checkL
	{
		int LUx, LUy, RDx, RDy;
		if (y1 < y2 && x1 < x2) //xac dinh Left Up , Right Down
		{
			LUx = x1;
			LUy = y1;
			RDx = x2;
			RDy = y2;
		}
		if (y1 > y2 && x1 > x2)
		{
			LUx = x2;
			LUy = y2;
			RDx = x1;
			RDy = y1;
		}
		// duong noi chu Z
	for (int i = LUy +1; i <= RDy -1;i++)
		if (checkcolumn(a,LUx,RDx,i)) 
			if (checkline(a,LUy+1,i,LUx)&&checkline(a,i,RDy-1,RDx)) 
				return true; 
	  // duong noi chu N
	for (int j = LUx + 1; j <= RDx - 1; j++)
		if (checkline(a, LUy, RDy ,j))
			if (checkcolumn(a, LUx + 1, j, LUy) && checkcolumn(a, j, RDx - 1, RDy))
				return true;
	return false;
	}
	if ((y1 > y2 && x1 < x2) || (y1 < y2 && x1 > x2))
	{
		int RUx, RUy, LDx, LDy;
		if (y1 > y2 && x1 < x2) // xac dinh Right Up, Left Down, sau do lam tuong tu o tren
		{
			RUx = x1;
			RUy = y1;
			LDx = x2;
			LDy = y2;
		}
		if (y1 < y2 && x1 > x2)
		{
			RUx = x2;
			RUy = y2;
			LDx = x1;
			LDy = y1;
		}
		for (int i = LDy + 1; i <= RUy - 1; i++)
			if (checkcolumn(a, RUx, LDx, i))
				if (checkline(a, LDy + 1, i, LDx) && checkline(a, i, RUy - 1, RUx))
					return true;
		for (int j = RUx + 1; j <= LDx - 1; j++)
			if (checkline(a, LDy, RUy, j))
				if (checkcolumn(a, RUx + 1, j, RUy) && checkcolumn(a, j, LDx - 1, LDy))
					return true;
		return false;
	}
}
bool checkU(char **a, int x1, int y1, int x2, int y2) {
	if (x1 == x2) // neu 2 o cung cot thi chi kiem tra duong noi hinh chu U nga ve trai va chu U nga ve phai
	{	//mang 2 chieu dua vao co cac gia tri o ngoai vien deu la khoang trong chinh la de kiem tra duong noi hinh chu U de dang hon
		for (int i = 0; i < x1; i++)
			if (checkline(a, min(y1, y2), max(y1, y2), i)) 
				if (checkcolumn(a, i, x1-1, y1) && checkcolumn(a, i, x2-1, y2))
					return true; 
		for (int i = x1 +1; i < 7; i++) 
			if (checkline(a, min(y1, y2), max(y1, y2), i)) 
				if (checkcolumn(a, x1 + 1, i, y1) && checkcolumn(a, x2 + 1, i,y2)) 
					return true;
		return false;
	}
	if (y1 == y2 ) // Neu 2 o cung hang thi kiem tra duong noi hinh chu U va chu U nguoc
	{
		for (int i = 0; i < y1; i++)  
			if (checkcolumn(a, min(x1, x2), max(x1, x2), i)) 
				if (checkline(a, i, y1 - 1, x1) && checkline(a, i, y2 - 1, x2)) 
					return true; 
		for (int i = y1 + 1; i < 8; i++) 
			if (checkcolumn(a, min(x1, x2), max(x1, x2), i))
				if (checkline(a, y1 + 1, i, x1) && checkline(a, y2 + 1, i, x2))
					return true;
		return false;
	}
	// neu 2 o khong cung hang cung khong cung cot thi kiem tra ca 4 chu U, cach lam nhu tren
	for (int i = 0; i < min(x1,x2); i++)
		if (checkline(a, min(y1, y2), max(y1, y2), i))
			if (checkcolumn(a, i, x1 - 1, y1) && checkcolumn(a, i, x2 -1, y2))
				return true;
	for (int i = max(x1,x2) + 1; i < 7; i++)
		if (checkline(a, min(y1, y2), max(y1, y2), i))
			if (checkcolumn(a, x1 + 1, i, y1) && checkcolumn(a, x2 + 1, i, y2))
				return true;
	for (int i = 0; i < min(y1,y2); i++)
		if (checkcolumn(a, min(x1, x2), max(x1, x2), i))
			if (checkline(a, i, y1 - 1, x1) && checkline(a, i, y2 - 1, x2))
				return true;
	for (int i = max(y1,y2) + 1; i < 8 ;i++)
		if (checkcolumn(a, min(x1, x2), max(x1, x2), i))
			if (checkline(a, y1 + 1, i, x1) && checkline(a, y2 + 1, i, x2))
				return true;
	return false;
}
void reset(int& count, int& x1, int& y1, int& x2, int& y2) {// ham gan cac bien luu gia tri hang va gia tri cot cua 2 o nguoi dung chon ve gia tri mac dinh
	count = 0;
	x1 = -1;
	x2 = -1;
	y1 = -1;
	y2 = -1;
}

