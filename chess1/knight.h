#pragma once
#include "piece.h"
class knight:
	public piece
{
public:
	knight();
	~knight();

	bool moveApplicable(int xl, int yl);
	bool attackApplicable(int xl, int yl);
};

