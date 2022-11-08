#include <iostream>
#include "Beverages.h"
#include "Condiments.h"

int main() {
	Beverage* beverage = new Espresso();
	std::cout << beverage->getDescription() << " " << beverage->cost() << std::endl;

	Beverage* beverage2 = new HouseBlend();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Soy(beverage2);
	beverage2 = new Ice(beverage2);
	std::cout << beverage2->getDescription() << " " << beverage2->cost() << std::endl;

	delete beverage;
	delete beverage2;
}
