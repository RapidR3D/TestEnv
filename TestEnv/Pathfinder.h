#pragma once

#include "Grid.h"
#include "Constants.h"

class Pathfinder
{
	Grid& gridRef;

	bool exploredCells[COLUMNS][ROWS]{}; //Dijkstra
	std::vector<std::pair<int, int>> dijkstraPath;

	int _sourceX;
	int _sourceY;

	int _destX;
	int _destY;
public:
	Pathfinder(Grid& grid);
	~Pathfinder()
	{
		std::cout << "Pathfinder deconstruction" << std::endl;
	}
	Tile _tile;

	void test() const;
	void init(int sourceX, int sourceY, int destX, int destY);

	void findMin(float distance[COLUMNS][ROWS], int& minX, int& minY);
	void findPath(std::pair<int, int> previous[COLUMNS][ROWS], float distance[COLUMNS][ROWS], int destX, int destY, int sourceX, int sourceY);
	
	//void dijkstra(int sourceX, int sourceY, int destX, int destY, int grid[COLUMNS][ROWS]);
	void dijkstra(int sourceX, int sourceY, int destX, int destY, Grid& grid);

	void pathfindInput(sf::Event& event);
	void drawGrid(sf::RenderWindow& window);
	
	int filled[COLUMNS][ROWS]{}; //Dijkstra
};

