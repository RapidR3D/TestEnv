#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

#include "Tile.h"
//#include "Pathfinder.h"
#include "Constants.h"

class Grid
{
	friend class Pathfinder;
	
	void createGrid();
	
	int grid[COLUMNS][ROWS]{};	
public:	
	Grid();
	~Grid()	{ std::cout << "Grid deconstruction" << std::endl; }
	
	Tile tile;		

	void draw(sf::RenderWindow& window);
	void test();	
};

