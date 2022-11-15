#pragma once
#include "Beverage.h"

class Coffee : public Beverage{
public:
	void brew() override {std::cout << "brewing coffee" << std::endl;}
	void addCondiments() {std::cout << "Add sugar and milk" << std::endl;}

	bool wantsCondiments() {
		char x;
		std::cout << "do you want milk and sugar? (y/n): ";
		std::cin >> x;
		return 'y' == tolower(x);
	}
};