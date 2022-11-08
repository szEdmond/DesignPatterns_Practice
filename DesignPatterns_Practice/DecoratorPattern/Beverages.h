#pragma once
#include "Beverage.h"
class Espresso : public Beverage {
public:
	std::string getDescription() override { return "Espresso"; }

	double cost() override {return 1.99;}
};

class HouseBlend : public Beverage {
public:
	std::string getDescription() override { return "HoseBlend"; }
	
	double cost() override{return 0.89;}
};
