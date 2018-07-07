#pragma once
#include "piece.h"
class king :
	public piece
{
public:
	king();
	~king();

	bool moveApplicable(int xl, int yl);
	bool attackApplicable(int xl, int yl);
};

