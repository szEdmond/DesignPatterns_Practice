#pragma once
#include "Beverage.h"

class Tea : public Beverage{
public:
	void brew() override {
		std::cout << "brewing tea" << std::endl;
	}
	void addCondiments() {
		std::cout << "adding lemon" << std::endl;
	}
	bool wantsCondiments() {
		char x;
		std::cout << "want lemon? (y / n): ";
		std::cin >> x;
		return 'y' == tolower(x);
	}
};