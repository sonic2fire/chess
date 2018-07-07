#include "queen.h"
#include <iostream>

using namespace std;


queen::queen()
{
	type = 'Q';
}


queen::~queen()
{
}

bool queen::moveApplicable(int xl, int yl)
{
	if ((abs(xl - prelocationX) == abs(yl - prelocationY)) || xl == prelocationX || yl == prelocationY) {
		return true;
	}

	else {
		cout << "Move is not applicable for Queen" << '\n';
		return false;
	}
}

bool queen::attackApplicable(int xl, int yl)
{
	if ((abs(xl - prelocationX) == abs(yl - prelocationY)) || xl == prelocationX || yl == prelocationY) {
		return true;
	}
	
	else {
		cout << "Attack is not applicable for Queen" << '\n';
		return false;
	}
}