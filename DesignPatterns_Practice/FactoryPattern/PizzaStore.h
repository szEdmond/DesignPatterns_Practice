#pragma once
#include <string>
#include "Pizza.h"

class PizzaStore {
public:
	void orderPizza(std::string type) {
		Pizza* pizza = createPizza(type);
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		delete pizza;
	}
protected:
	virtual Pizza* createPizza(std::string type) = 0;};


// -------------- PIZZASTORES ----------------------

class NYPizzaStore : public PizzaStore {
	Pizza* createPizza(std::string item) override{
		if (item == "cheese")
			return new NYStyleCheesePizza();
		else if (item == "pepperoni")
			return new NYStylePepperoniPizza();
		else return nullptr;
	}
};

class ChicagoPizzaStore : public PizzaStore {
	Pizza* createPizza(std::string item) override{
		if (item == "cheese")
			return new ChicagoStyleCheesePizza();
		else if (item == "pepperoni")
			return new ChicagoStylePepperoniPizza();
		else return nullptr;
	}
};
