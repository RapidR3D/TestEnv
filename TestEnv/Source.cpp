#include "Engine.h"
#include <iostream>


#include "Grid.h"

int main()
{	
	Engine engine(640, 480);
	try
	{
		engine.run();
	}	
	catch (std::exception* e)  // NOLINT(cert-err09-cpp)
	{
		std::cerr << "Engine try/catch method exception: " << e << std::endl;
		EXIT_SUCCESS;
	}	
	return 0;
}
