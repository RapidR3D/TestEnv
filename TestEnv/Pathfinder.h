#pragma once

#include "Grid.h"
#include "Constants.h"

class Pathfinder
{
	Grid& gridRef;
public:
	Pathfinder(Grid& grid);

	void test();
};

