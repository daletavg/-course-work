#include "inventary.h"



inventary::inventary()
{
	for (size_t i = 0; i < 4; i++)
	{
		_inventary.push_back(NullBlock);
	}
}


inventary::~inventary()
{
}
