class cell {
public:
	bool visited; //to prevent cycles
	bool walls[4] = { true,true,true,true };   //up, down, right, left
	enum directions { up = 0, down = 1, right = 2, left = 3 };
	int x, y;  //row and column
	cell(int x, int y);
};

