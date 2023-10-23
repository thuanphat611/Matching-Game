#pragma once
struct cell {
	char value;
	cell* next;
};
struct list {
	cell* head;
};
cell* getCell(char k);
list* genBoardLL(int boardSize);