#pragma once

class piece
{
public:
	piece();
	~piece();
	void setDefault(int locationX,int locationY,int player,char type);
	void move(int mlocationX, int mlocationY);
	void moveAccepted(bool);
	void changeTypePlayer(char type, int player);
	void setLocation(int x, int y);

	int locationX;
	int locationY;
	int prelocationX;
	int prelocationY;


	char type;
	int player;
	bool hasMoved;
};



