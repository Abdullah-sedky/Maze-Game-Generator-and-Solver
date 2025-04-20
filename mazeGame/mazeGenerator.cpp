#include "mazeGenerator.h"
#include<iostream>
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
	}hggggggggggg
	else {
		generatePrim();
	}
}

void mazeGenerator::generateDFS()
{
	
}

void mazeGenerator::generatePrim(){
	
}

void mazeGenerator::printMaze()
{
}
