#pragma once
#include "Condiment.h"
#include "Beverage.h"

class Mocha : public CondimentDecorator {
public:
	Mocha(Beverage* beverage) : CondimentDecorator(beverage) {}

	std::string getDescription() override {
		return m_beverage->getDescription() + ", Mocha";
	}
	double cost() override {
		return m_beverage->cost() + 0.20;
	}
};

class Soy : public CondimentDecorator {
public:
	Soy(Beverage* _beverage) : CondimentDecorator(_beverage) {}

	std::string getDescription() override {
		return m_beverage->getDescription() + ", Soy";
	}
	double cost() override {
		return m_beverage->cost() + 0.15;
	}
};

class Ice : public CondimentDecorator {
public:
	Ice(Beverage* _beverage) : CondimentDecorator(_beverage) {}

	std::string getDescription() override {
		return m_beverage->getDescription() + ", Ice";
	}
	double cost() override {
		return m_beverage->cost() + 0.05;
	}
};
