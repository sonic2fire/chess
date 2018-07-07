#pragma once
#include "piece.h"
class queen :
	public piece
{
public:
	queen();
	~queen();

	bool moveApplicable(int xl, int yl);
	bool attackApplicable(int xl, int yl);
};

