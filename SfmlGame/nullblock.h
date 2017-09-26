#pragma once
#include "frame.h"
class nullblock :
	public frame
{
public:
	nullblock() {
		setName("nullblock");
		setRectPos(-1000, -1000, 2, 2);
		setDraw(false);
	}
};

static nullblock* NullBlock = new nullblock();