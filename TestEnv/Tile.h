#pragma once

#include <SFML\Graphics.hpp>

struct Tile
{
	sf::RectangleShape originNode;
	sf::RectangleShape destNode;
	sf::RectangleShape obstacle;
	sf::RectangleShape empty;
	sf::RectangleShape searchedCell;

	int tPosX;
	int tPosY;

	sf::Vector2f tilePosition;

	//Tile() {}
};

