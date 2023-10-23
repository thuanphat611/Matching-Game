#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct player {
	string name;
	int playtime;
};
void moveSuggestion(char** a);
void sortfile(string filename);
void printLB(string filename);
void deleteBlank(char** a);