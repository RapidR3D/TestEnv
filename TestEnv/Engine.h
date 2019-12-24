#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

#include "Grid.h"
#include "Pathfinder.h"
#include "Constants.h"

class Engine
{
	sf::RenderWindow window;
	sf::RectangleShape testRect;
	
public:
	Engine(int /*width*/, int /*height*/);
	~Engine()
	{
		std::cout << "Engine deconstruction" << std::endl;
	}

	Grid grid;
	Pathfinder pf;
	
	void processInput();	
	void render();	
	void run();
};

