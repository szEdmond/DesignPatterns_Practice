#pragma once
#include <string>
#include <vector>
#include <iostream>

class Pizza {
public:
	void prepare() {
		std::cout << "Preparing " << name << std::endl;
		std::cout << "Tossing dough..." << std::endl;
		std::cout << "Adding sauce..." << std::endl;
		std::cout << "Adding toppings: " << std::endl;
		for (const std::string& topping : toppings) {
			std::cout << "\t" << topping << std::endl;
		}
	}
	void bake() { std::cout << "Bake for 25 minutes at 350" << std::endl; }
	virtual void cut() { std::cout << "Cutting diagonally" << std::endl; }
	void box() { std::cout << "Place pizza into box" << std::endl; }
	std::string getName() { return name; }

	~Pizza() {};
protected:
	std::string name;
	std::string dough;
	std::string sauce;
	std::vector<std::string> toppings;
};

// -----------------------------------

class NYStyleCheesePizza : public Pizza {
public:
	NYStyleCheesePizza() {
		name = "NY Style Cheese Pizza";
		dough = "Thin dough";
		sauce = "Marinara Sauce";

		toppings.push_back("Grated Cheese");
	}
};

class NYStylePepperoniPizza : public Pizza {
public:
	NYStylePepperoniPizza() {
		name = "NY Style Pepperoni Pizza";
		dough = "Thin dough";
		sauce = "Marinara Sauce";

		toppings.push_back("Extra Pepperoni");
	}
};

// -----------------------------------

class ChicagoStyleCheesePizza : public Pizza {
public:
	ChicagoStyleCheesePizza() {
		name = "Chicago Style Cheese Pizza";
		dough = "Thicc dough";
		sauce = "Tomato Sauce";

		toppings.push_back("Mozzarella Cheese");
	}
	void cut() { std::cout << "Cutting into square slices" << std::endl; }
};

class ChicagoStylePepperoniPizza : public Pizza {
public:
	ChicagoStylePepperoniPizza() {
		name = "Chicago Style Pepperoni Pizza";
		dough = "Thicc dough";
		sauce = "Tomato Sauce";

		toppings.push_back("Extra Pepperoni");
	}
	void cut() { std::cout << "Cutting into square slices" << std::endl; }
};


