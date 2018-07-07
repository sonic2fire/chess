#include "knight.h"
#include <cmath>
#include <iostream>

using namespace std;

knight::knight()
{
	type = 'H';
}


knight::~knight()
{
}

bool knight::moveApplicable(int xl, int yl)
{
	if ((abs(xl-prelocationX)==2 && abs(yl-prelocationY)==1) || (abs(xl - prelocationX) == 1 && abs(yl - prelocationY) == 2)) {
		return true;
	}
	else {
		cout << "Move is not applicable for knight" << '\n';
		return false;
	}
}

bool knight::attackApplicable(int xl, int yl)
{
	if ((abs(xl - prelocationX) == 2 && abs(yl - prelocationY) == 1) || (abs(xl - prelocationX) == 1 && abs(yl - prelocationY) == 2)) {
		return true;
	}
	else {
		cout << "Attack is not applicable for knight" << '\n';
		return false;
	}
}