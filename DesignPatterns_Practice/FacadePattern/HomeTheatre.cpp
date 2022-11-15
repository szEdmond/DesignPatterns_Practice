#include "HomeTheatreFacade.h"

int main()
{
	Lights light;
	Speaker speaker;
	Projector projector;

	HomeTheatreController homeTheatreController(projector, speaker, light);


	homeTheatreController.watchMovie("Pirates of the Carribbean");
	std::cout << "\n\tThe End" << std::endl;
	homeTheatreController.turnOff();

	_CrtDumpMemoryLeaks();
}