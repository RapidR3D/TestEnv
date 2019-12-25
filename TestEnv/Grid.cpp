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
}

void Grid::draw(sf::RenderWindow& window)
{
	for (int i = 0; i <= 630; i += CELLSIZE)
	{
		for (int j = 0; j <= 470; j += CELLSIZE)
		{
			if (grid[i / CELLSIZE][j / CELLSIZE] == 0)
			{
				tile._default.setSize(sf::Vector2f(CELLSIZE - 1, CELLSIZE - 1));				
				tile._default.setFillColor(sf::Color::White);
				tile._default.setPosition(i, j);
				window.draw(tile._default); //set up default
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
