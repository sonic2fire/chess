#include "pawn.h"
#include <cmath>
#include <iostream>

using namespace std;

pawn::pawn()
{
	type = 'P';
}


pawn::~pawn()
{
}

bool pawn::moveApplicable(int xl,int yl)
{
	if (!hasMoved) {
		if (yl == prelocationY && (abs(xl-prelocationX)==2 || abs(xl - prelocationX) == 1 )) {
			return true;
		}
		else {
			cout << "Move is not Applicable for pawn";
			return false;
		}
	}
	else if (yl == prelocationY &&  abs(xl - prelocationX) == 1) {
		return true;
	}
	else {
		cout << "Move is not applicable for pawn"<<'\n';
		return false;
	}
}

bool pawn::attackApplicable(int xl, int yl)
{
	if (abs(xl - prelocationX) == 1 && abs(yl - prelocationY) == 1) {
		return true;
	}
	else {
		cout << "Attack is not applicable for pawn" << '\n';
		return false;
	}
}
