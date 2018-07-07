#include "piece.h"



piece::piece()
{
	type = '0';
	locationX = 0;
	locationY = 0;
	prelocationX = 0;
	prelocationY = 0;
	hasMoved = false;
	player = 0;
}


piece::~piece()
{
}

void piece::setDefault(int lx, int ly, int p,char t)
{
	locationX = lx;
	locationY = ly;
	prelocationX = lx;
	prelocationY = ly;
	player = p;
	type = t;
}

void piece::move(int lx, int ly)
{
	locationX = lx;
	locationY = ly;
}

void piece::moveAccepted(bool t)
{
	if (t) {
		prelocationX = locationX;
		prelocationY = locationY;
	}
	else {
		locationX = prelocationX;
		locationY = prelocationY;
	}
}

void piece::changeTypePlayer(char t, int p)
{
	type = t;
	player = p;
}

void piece::setLocation(int x, int y)
{
	locationX = x;
	locationY = y;
	prelocationX = locationX;
	prelocationY = locationY;

}

