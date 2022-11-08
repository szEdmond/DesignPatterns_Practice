#pragma once
#include "Beverage.h"
class CondimentDecorator : public Beverage {
public:
	CondimentDecorator(Beverage* b) : m_beverage(b) {}
	~CondimentDecorator() { delete m_beverage; }

	virtual std::string getDescription() = 0;

	Beverage* m_beverage;
};
