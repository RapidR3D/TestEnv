#include "Pathfinder.h"

Pathfinder::Pathfinder(Grid& grid): gridRef(grid)
{
	std::cout << "Pathfinder constructor" << std::endl;

	_sourceX = 2;
	_sourceY = 4;

	_destX = 60;
	_destY = 42;

	init(_sourceX, _sourceY, _destX, _destY);	
}

void Pathfinder::test() const
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

void Pathfinder::init(int sourceX, int sourceY, int destX, int destY)
{
	this->_destX = destX;
	this->_destY = destY;
	this->_sourceX = sourceX;
	this->_sourceY = sourceY;

	filled[_sourceX][_sourceY] = 1;
	filled[_destX][_destY] = 1;

	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			exploredCells[i][j] = false;
			filled[i][j] = 0;
		}
	}
}

void Pathfinder::findMin(float distance[COLUMNS][ROWS], int& minX, int& minY)
{
	float minTemp = FLT_MAX;
	for(int i = 0; i < COLUMNS; i++)
	{
		for(int j = 0; j < ROWS; j++)
		{
			if(exploredCells[i][j] == false && distance[i][j] < minTemp)
			{
				minTemp = distance[i][j];
				minX = i;
				minY = j;
			}
		}
	}
}

void Pathfinder::findPath(std::pair<int, int> previous[COLUMNS][ROWS], float distance[COLUMNS][ROWS], int destX, int destY, int sourceX, int sourceY)
{
 	this->_destX = destX;
 	this->_destY = destY;
 	this->_sourceX = sourceX;
 	this->_sourceY = sourceY;	
	
	std::cout << "Dijkstra: " << distance[destX][destY] << "\n";
	while(previous[destX][destY].first != sourceX || previous[destX][destY].second != sourceY)
	{
		sf::sleep(sf::milliseconds(10));
		std::cout << "\n(" << previous[destX][destY].first << ", " << previous[destX][destY].second << ") " << "go to ->";
		dijkstraPath.push_back(std::make_pair(previous[destX][destY].first, previous[destX][destY].second));
		//dijkstraPath.emplace_back(previous[destX][destY].first, previous[destX][destY].second);

		const int saveX = destX;
		const int saveY = destY;

		destX = previous[saveX][saveY].first;
		destY = previous[saveX][saveY].second;
	}
}

void Pathfinder::dijkstra(int sourceX, int sourceY, int destX, int destY, Grid& grid)
{
	this->_destX = destX;
	this->_destY = destY;
	this->_sourceX = sourceX;
	this->_sourceY = sourceY;

	this->gridRef =  grid;	
	
	std::pair<int, int> previous[COLUMNS][ROWS];
	float _distance[COLUMNS][ROWS];
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			_distance[i][j] = FLT_MAX;
		}
	}
	_distance[sourceX][sourceY] = 0.0;
	int found = 0;

	for (int i = 0; i < COLUMNS && found == 0; i++)
		for (int j = 0; j < ROWS && found == 0; j++)
		{
			int minX = 0;
			int minY = 0;

			findMin(_distance, minX, minY);

			exploredCells[minX][minY] = true;
			if (exploredCells[destX][destY] == true)
			{
				found = 1;
				break;
			}

			sf::sleep(sf::milliseconds(1)); 
			//north
			if (gridRef.grid[minX - 1][minY] == 1 && exploredCells[minX - 1][minY] == false && _distance[minX - 1][minY] > _distance[minX][minY] + 1.0f) 
			{
				_distance[minX - 1][minY] = _distance[minX][minY] + 1.0;
				previous[minX - 1][minY] = std::make_pair(minX, minY);
			}
			//south
			if (gridRef.grid[minX + 1][minY] == 1 && exploredCells[minX + 1][minY] == false && _distance[minX + 1][minY] > _distance[minX][minY] + 1.0f) 
			{
				_distance[minX + 1][minY] = _distance[minX][minY] + 1.0;
				previous[minX + 1][minY] = std::make_pair(minX, minY);
			}
			//west
			if (gridRef.grid[minX][minY - 1] == 1 && exploredCells[minX][minY - 1] == false && _distance[minX][minY - 1] > _distance[minX][minY] + 1.0f) 
			{
				_distance[minX][minY - 1] = _distance[minX][minY] + 1.0;
				previous[minX][minY - 1] = std::make_pair(minX, minY);
			}
			//east:i,j+1
			if (gridRef.grid[minX][minY + 1] == 1 && exploredCells[minX][minY + 1] == false && _distance[minX][minY + 1] > _distance[minX][minY] + 1.0f) 
			{
				_distance[minX][minY + 1] = _distance[minX][minY] + 1.0;
				previous[minX][minY + 1] = std::make_pair(minX, minY);
			}
			//north-east:i-1,j+1
			if (gridRef.grid[minX - 1][minY + 1] == 1 && exploredCells[minX - 1][minY + 1] == false && _distance[minX - 1][minY + 1] > _distance[minX][minY] + sqrt(2) && !(gridRef.grid[minX - 1][minY] == 0 && gridRef.grid[minX][minY + 1] == 0)) 
			{
				_distance[minX - 1][minY + 1] = _distance[minX][minY] + sqrt(2);
				previous[minX - 1][minY + 1] = std::make_pair(minX, minY);
			}
			//south-east:i+1,j+1
			if (gridRef.grid[minX + 1][minY + 1] == 1 && exploredCells[minX + 1][minY + 1] == false && _distance[minX + 1][minY + 1] > _distance[minX][minY] + sqrt(2) && !(gridRef.grid[minX + 1][minY] == 0 && gridRef.grid[minX][minY + 1] == 0))
			{
				_distance[minX + 1][minY + 1] = _distance[minX][minY] + sqrt(2);
				previous[minX + 1][minY + 1] = std::make_pair(minX, minY);
			}
			//south-west:i+1,j-1
			if (gridRef.grid[minX + 1][minY - 1] == 1 && exploredCells[minX + 1][minY - 1] == false && _distance[minX + 1][minY - 1] > _distance[minX][minY] + sqrt(2) && !(gridRef.grid[minX + 1][minY] == 0 && gridRef.grid[minX][minY - 1] == 0))
			{
				_distance[minX + 1][minY - 1] = _distance[minX][minY] + sqrt(2);
				previous[minX + 1][minY - 1] = std::make_pair(minX, minY);
			}
			//north-west:i-1,j-1
			if (gridRef.grid[minX - 1][minY - 1] == 1 && exploredCells[minX - 1][minY - 1] == false && _distance[minX - 1][minY - 1] > _distance[minX][minY] + sqrt(2) && !(gridRef.grid[minX - 1][minY] == 0 && gridRef.grid[minX][minY - 1] == 0)) 
			{
				_distance[minX - 1][minY - 1] = _distance[minX][minY] + sqrt(2);
				previous[minX - 1][minY - 1] = std::make_pair(minX, minY);
			}
		}
	findPath(previous, _distance, destX, destY, sourceX, sourceY);
}

void Pathfinder::pathfindInput(sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{//handle mouse
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//std::cout << "Left Mouse pressed" << std::endl;
			int x = event.mouseButton.x;
			int y = event.mouseButton.y;
			const int column = x / CELLSIZE;
			const int row = y / CELLSIZE;

			if (gridRef.grid[column][row] == 0 && column < 63 && row < 47)
			{
				gridRef.grid[column][row] = 1;				
			}			
			else if (column < 63 && row < 47)
			{
				gridRef.grid[column][row] = 0;				
			}
			//std::cout << "Cell " << row << ", " << column << " state is: " << gridRef.grid[row][column] << std::endl;			
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			dijkstra(_sourceX, _sourceY, _destX, _destY, gridRef);
		}
	}
}

void Pathfinder::drawGrid(sf::RenderWindow& window)
{
	if (!dijkstraPath.empty())
	{
		for (int i = 0; i < dijkstraPath.size(); i++)
		{ 			
			filled[dijkstraPath[i].first][dijkstraPath[i].second] = 1;
		}
	}
	for (int i = 0; i <= 630; i += CELLSIZE)
	{
		for (int j = 0; j <= 470; j += CELLSIZE)
		{ 			
			if (gridRef.grid[i / CELLSIZE][j / CELLSIZE] == 1 && filled[i / CELLSIZE][j / CELLSIZE] == 1)
			{
				_tile.path.setSize(sf::Vector2f(CELLSIZE, CELLSIZE));
				_tile.path.setFillColor(sf::Color::Green);
				_tile.path.setOutlineColor(sf::Color::Black);
				_tile.path.setOutlineThickness(2);
				_tile.path.setPosition(i, j);
				window.draw(_tile.path);//path
			}
			if (gridRef.grid[i / CELLSIZE][j / CELLSIZE] == 1 && filled[i / CELLSIZE][j / CELLSIZE] == 0)
			{
				_tile.searchedCell.setSize(sf::Vector2f(CELLSIZE, CELLSIZE));
				_tile.searchedCell.setFillColor(sf::Color(255, 102, 102));
				_tile.searchedCell.setOutlineColor(sf::Color::Black);
				_tile.searchedCell.setOutlineThickness(2);
				_tile.searchedCell.setPosition(i, j);
				window.draw(_tile.searchedCell);//searched by Dijkstra
			}
			if (gridRef.grid[i / CELLSIZE][j / CELLSIZE] == 0) 
			{
				_tile.obstacle.setSize(sf::Vector2f(CELLSIZE - 1, CELLSIZE - 1));
				_tile.obstacle.setOutlineThickness(2);
				_tile.obstacle.setOutlineColor(sf::Color::White);
				_tile.obstacle.setFillColor(sf::Color::Black);
				_tile.obstacle.setPosition(i, j);
				window.draw(_tile.obstacle);        //obstacle
			}			
 			if (gridRef.grid[i / CELLSIZE][j / CELLSIZE] == 1 && exploredCells[i / CELLSIZE][j / CELLSIZE] == false && filled[i / CELLSIZE][j / CELLSIZE] == 0) 
			{     //not in dijkstra & A*
				_tile._default.setSize(sf::Vector2f(CELLSIZE - 1, CELLSIZE - 1));
				_tile._default.setOutlineThickness(.5);
				_tile._default.setOutlineColor(sf::Color::Red);
				_tile._default.setFillColor(sf::Color::White);
				_tile._default.setPosition(i, j);
				window.draw(_tile._default);     //default
			}			
		}
	}

	_tile.originNode.setSize(sf::Vector2f(CELLSIZE, CELLSIZE));
	_tile.originNode.setOutlineColor(sf::Color::Blue);
	_tile.originNode.setOutlineThickness(1);
	_tile.originNode.setFillColor(sf::Color::Green);
	_tile.originNode.setPosition(CELLSIZE * _sourceX, CELLSIZE * _sourceY);
	window.draw(_tile.originNode);

	_tile.destNode.setSize(sf::Vector2f(CELLSIZE, CELLSIZE));
	_tile.destNode.setOutlineColor(sf::Color::Green);
	_tile.destNode.setOutlineThickness(1);
	_tile.destNode.setFillColor(sf::Color::Blue);
	_tile.destNode.setPosition(CELLSIZE * _destX, CELLSIZE * _destY);
	window.draw(_tile.destNode);
}
