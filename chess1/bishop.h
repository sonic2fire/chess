#pragma once
#include "piece.h"
class bishop :
	public piece
{
public:
	bishop();
	~bishop();

	bool moveApplicable(int xl, int yl);
	bool attackApplicable(int xl, int yl);
};

