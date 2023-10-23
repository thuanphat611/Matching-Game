#pragma once
#include "board.h"
void move(int xMax, int yMax, int& sx, int& sy, char command);
bool checkline(char **a, int start, int end, int row);
bool checkcolumn(char **a, int start, int end, int column);
bool checkI(char **a, int x1, int y1, int x2, int y2);
bool checkL(char **a, int x1, int y1, int x2, int y2);
bool checkZ(char **a, int x1, int y1, int x2, int y2);
bool checkU(char **a, int x1, int y1, int x2, int y2);
void reset(int& count, int& x1, int& y1, int& x2, int& y2);
