#include "king.h"
#include <iostream>
#include <cmath>
using namespace std;


king::king()
{
	type = 'K';
}


king::~king()
{
}

bool king::moveApplicable(int xl, int yl)
{
	if (abs(xl-prelocationX)<=1 && abs(yl - prelocationY) <= 1) {
		return true;
	}
	else {
		cout << "Move is not applicable for king" << '\n';
		return false;
	}
}

bool king::attackApplicable(int xl, int yl)
{
	if (abs(xl - prelocationX) <= 1 && abs(yl - prelocationY) <= 1) {
		return true;
	}
	else {
		cout << "Attack is not applicable for king" << '\n';
		return false;
	}
}