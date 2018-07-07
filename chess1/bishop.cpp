#include "bishop.h"
#include <iostream>

using namespace std;


bishop::bishop()
{
	type = 'B';
}


bishop::~bishop()
{
}


bool bishop::moveApplicable(int xl, int yl)
{
	if (abs(xl-prelocationX)==abs(yl-prelocationY)) {
		return true;
	}
	else {
		cout << "Move is not applicable for bishop" << '\n';
		return false;
	}
}

bool bishop::attackApplicable(int xl, int yl)
{
	if (abs(xl - prelocationX) == abs(yl - prelocationY)) {
		return true;
	}
	else {
		cout << "Attack is not applicable for bishop" << '\n';
		return false;
	}
}