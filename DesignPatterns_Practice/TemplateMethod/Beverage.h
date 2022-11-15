#pragma once
#include <iostream>

class Beverage {
public:
	virtual void prepare() final
	{
		boilWater();
		brew();
		pour();
		if (wantsCondiments()) {
			addCondiments();
		}
	}

	virtual void brew() = 0;
	virtual void addCondiments() = 0;

	void boilWater() {std::cout << "Boiling Water" << std::endl;}
	void pour() {std::cout << "Pouring..." << std::endl;}
	virtual bool wantsCondiments() {return true;}
};