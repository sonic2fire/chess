#include "rook.h"
#include <iostream>

using namespace std;

rook::rook()
{
	type = 'R';
}


rook::~rook()
{
}

bool rook::moveApplicable(int xl, int yl)
{
	if (xl == prelocationX || yl == prelocationY) {
		return true;
	}
	else {
		cout << "Move is not applicable for rook"<<'\n';
		return false;
	}
}

bool rook::attackApplicable(int xl, int yl)
{
	if (xl == prelocationX || yl == prelocationY) {
		return true;
	}
	else {
		cout << "Attack is not applicable for rook" << '\n';
		return false;
	}
}