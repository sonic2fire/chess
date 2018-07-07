#pragma once
#include "piece.h"
class rook :
	public piece
{
public:
	rook();
	~rook();

	bool moveApplicable(int xl, int yl);
	bool attackApplicable(int xl, int yl);
};

