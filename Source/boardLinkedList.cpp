#include <iostream>
#include <cstdlib>
#include"boardLinkedList.h"
#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
cell* getCell(char k) {// ham tao o
	cell* p = new cell;
	p->next = NULL;
	p->value = k;
	return p;
}
list * genBoardLL(int boardSize) {// ham tao bang bang linked list
	list* board = new list;
	board->head = NULL;

	
	int rd[8] = { 4,4,4,4,4,4,4,2 }; // mang quy dinh so lan xuat hien cua cac chu cai tu A toi H, o day chi co 4+4+4+4+4+4+4+2 = 30 o
	int random;

	random = rand() % 8;
	board->head = getCell('A' + random);
	rd[random]--;
	random = rand() % 8;

	cell* p = board->head;

	for (int i = 1; i < boardSize ;i++)
	{
		while (rd[random] == 0)
		{
			random = rand() % 8;
		}
		 p->next = getCell('A' + random);
		 p = p->next;
		 rd[random]--;
		random = rand() % 8;
	}
	return board;
}