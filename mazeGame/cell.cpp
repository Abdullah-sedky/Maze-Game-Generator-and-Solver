#include "cell.h"

cell::cell(int x, int y)
{
	x = x;
	y = y;
	isWall = false;
	isVisited = false;
}
void cell::setWall(bool state)
{ 
	isWall = state;
}
void cell::setVisited(bool state)
{
	isVisited = state;
}
;


