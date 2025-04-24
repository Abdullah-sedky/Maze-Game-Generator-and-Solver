#pragma once
#include<iostream>
#include<vector>
#include"cell.h"
using namespace std;
enum Difficulty {
	 Easy, Medium, Hard
};
struct mazeInfo {
	int height, width, wallCount;
	string algorithmUsed;
};
class mazeGenerator {
	mazeGenerator(Difficulty);
	void generateDFS();
	void generatePrim();
	void printMaze();
	vector<vector<cell>> maze; 
};