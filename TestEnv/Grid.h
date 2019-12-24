#pragma once

#include <SFML\Graphics.hpp>

#include <iostream>

#include "Tile.h"


#include "Constants.h"

class Grid
{
	friend class Pathfinder;
	
	void createGrid();

	int filled[COLUMNS][ROWS]{};
	int grid[COLUMNS][ROWS]{};

	static int getGrid(Grid* grid);
public:	
	Grid();
	~Grid()	{ std::cout << "Grid deconstruction" << std::endl; }
	
	Tile tile;	
	
	void drawGrid(sf::RenderWindow& window);
	void test();	
};

