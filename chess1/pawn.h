#pragma once
#include "piece.h"
class pawn :
	public piece
{
public:
	pawn();
	~pawn();

	bool moveApplicable(int xl,int yl);
	bool attackApplicable(int xl, int yl);

};

