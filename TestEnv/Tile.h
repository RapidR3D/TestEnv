#pragma once

#include <SFML\Graphics.hpp>

struct Tile
{
	sf::RectangleShape originNode;
	sf::RectangleShape destNode;	
	sf::RectangleShape path;
	sf::RectangleShape searchedCell;

	sf::RectangleShape empty;
	sf::RectangleShape _default;
	sf::RectangleShape obstacle;	
};

