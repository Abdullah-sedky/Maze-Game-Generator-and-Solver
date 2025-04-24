#include "mazeGenerator.h"
#include<iostream>
#include<stack>
using namespace std;

mazeInfo newMaze;

mazeGenerator::mazeGenerator(Difficulty diff)
{
	switch (diff)
	{
	case Easy:
		newMaze.height = 30;
		newMaze.width = 40;
		newMaze.wallCount = newMaze.height*newMaze.width*0.25;
		newMaze.algorithmUsed = "dfs";
		break;
	case Medium:
		newMaze.height = 50;
		newMaze.width = 80;
		newMaze.wallCount = newMaze.height * newMaze.width * 0.5;
		newMaze.algorithmUsed = "prim";
		break;
	case Hard:
		newMaze.height = 90;
		newMaze.width = 150;
		newMaze.wallCount = newMaze.height * newMaze.width * 0.8;
		newMaze.algorithmUsed = "prim";
		break;
	default:
		break;
	}
	if (newMaze.algorithmUsed == "dfs") {
		generateDFS();
	}
	else {
		generatePrim();
	}
}

void mazeGenerator::generateDFS()
{
	vector<vector<cell>> dfsMaze(newMaze.height, vector<cell>(newMaze.width));
	for (int i = 0; i < newMaze.height; i++) {
		for (int j = 0; j < newMaze.width; j++) {
			dfsMaze[i][j] = cell(i, j);
		}
	}
	stack<pair<int, int>> cellStack;
	vector<pair<int, int>> directions = { {0,1}, {0,-1}, {1,0}, {-1,0} };
	int mazeStart1 = rand() % newMaze.height;
	int mazeStart2 = rand() % newMaze.width;
	cellStack.push({ mazeStart1, mazeStart2 });
	dfsMaze[mazeStart1][mazeStart2].visited = true;
	while (!cellStack.empty()) {
		pair<int, int> current = cellStack.top();
		int currentRow = current.first;
		int currentColumn = current.second;
		vector<pair<int, int>> unvisitedCells;
		for (auto dir : directions) {    //loop on all directions to check all unvisited cells
			int nextRow = currentRow + dir.first;
			int nextColumn = currentColumn + dir.second;
			if (nextRow >= 0 && nextRow < newMaze.height && nextColumn >= 0 && nextColumn < newMaze.width && !dfsMaze[nextRow][nextColumn].visited) {
				unvisitedCells.push_back({ nextRow,nextColumn });
			}
		}
		if (!unvisitedCells.empty()) {  //choose a random unvisited neighbor

			//remove a wall between source and destination
			//
			///

			pair<int, int> chosenNeighbor = unvisitedCells[rand() % unvisitedCells.size()];
			dfsMaze[current.first][current.second].visited = true;
			cellStack.push({ chosenNeighbor.first,chosenNeighbor.second });
		}
		else {
			cellStack.pop();
		}

	}
}

void mazeGenerator::generatePrim(){
	
}

void mazeGenerator::printMaze()
{
}
