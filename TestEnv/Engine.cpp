#include "Engine.h"


Engine::Engine(int /*width*/, int /*height*/) :
	window(sf::VideoMode(WIDTH, HEIGHT), "Test Environment"), pf(grid)
{
	std::cout << "Engine constructor" << std::endl;
}

void Engine::processInput()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::KeyPressed)
		{//handle keyboard
			if (event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			if (event.key.code == sf::Keyboard::Space)
			{
				std::cout << "space bar" << std::endl;				
			}
			if (event.key.code == sf::Keyboard::G)
			{
				std::cout << "G" << std::endl;
				grid.test();
			}
			if (event.key.code == sf::Keyboard::P)
			{
				std::cout << "P" << std::endl;
				pf.test();
			}
		}
		pf.pathfindInput(event);
	}
}

void Engine::render()
{
	window.clear();
	grid.draw(window);
	pf.drawGrid(window);	
	window.display();
}

void Engine::run()
{
	while (window.isOpen())
	{
		processInput();
		render();
	}
}