#include "PizzaStore.h"

int main() {
	PizzaStore* nyPizzaStore = new NYPizzaStore();
	nyPizzaStore->orderPizza("cheese");
	std::cout << std::endl;

	PizzaStore* chicago = new ChicagoPizzaStore();
	chicago->orderPizza("cheese");
	
	delete nyPizzaStore;
	delete chicago;

	//_CrtDumpMemoryLeaks();
}