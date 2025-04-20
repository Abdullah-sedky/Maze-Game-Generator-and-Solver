class cell {
public:
	bool isVisited; //for exploration
	bool isWall;   //wall or path
	int x, y;  //coordinates for cell
	cell(int x, int y);
	void setWall(bool state);
	void setVisited(bool state);
};

