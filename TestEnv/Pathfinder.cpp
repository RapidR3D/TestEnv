#include "Pathfinder.h"

Pathfinder::Pathfinder(Grid& grid): gridRef(grid)
{
}

void Pathfinder::test()
{
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			std::cout << "ELEMENT at _gridRef<PATHFINDER>[" << i << "][" << j << "]: ";
			std::cout << gridRef.grid[i][j] << std::endl;
		}
	}
}
