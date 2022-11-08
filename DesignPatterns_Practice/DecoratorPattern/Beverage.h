#pragma once

class Beverage {
public:
	virtual ~Beverage(){}
	virtual double cost() = 0;
	virtual std::string getDescription() = 0;
};

