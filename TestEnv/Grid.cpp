#include "Grid.h"

Grid::Grid()
{	
	std::cout << "Grid constructor" << std::endl;
	createGrid();
}

void Grid::createGrid()
{
	for(int i = 0; i < COLUMNS; i++)
	{
		for(int j = 0; j < ROWS; j++)
		{
			if(i == 0 || i == 63 || j == 0 || j == 47)
			{
				grid[i][j] = 0;
			}
			else
			{
				grid[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			filled[i][j] = 0;
		}
	}
}

int Grid::getGrid(Grid* grid)
{
// 	for (int i = 0; i < COLUMNS; i++)
// 	{
// 		for (int j = 0; j < ROWS; j++)
// 		{
// 			std::cout << "getGrid()<GRID>[" << i << "][" << j << "]: ";
// 			std::cout << grid->grid[i][j] << std::endl;
// 		}
// 	}
	return grid->grid[COLUMNS - 1][ROWS - 1];
}

void Grid::drawGrid(sf::RenderWindow& window)
{
	for (int i = 0; i <= 630; i += 10)
	{
		for (int j = 0; j <= 470; j += 10)
		{
			if(grid[i / CELLSIZE][j / CELLSIZE] == 1 && filled[i / CELLSIZE][j / CELLSIZE] == 0)
			{
				tile.empty.setSize(sf::Vector2f(CELLSIZE, CELLSIZE));
				tile.empty.setOutlineColor(sf::Color::Green); 
				tile.empty.setOutlineThickness(2);
				tile.empty.setPosition(i, j);
				window.draw(tile.empty);
			}
		}
	}
}

void Grid::test()
{
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			std::cout << "ELEMENT at _grid<GRID>[" << i << "][" << j << "]: ";
			std::cout << grid[i][j] << std::endl;
		}
	}
}
