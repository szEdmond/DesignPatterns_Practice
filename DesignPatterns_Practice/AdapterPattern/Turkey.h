#pragma once
#include <iostream>

struct Turkey {
	virtual void gobble() = 0;
	virtual void fly() = 0;
};

struct WildTurkey : public Turkey{
	void gobble() { std::cout << "Gobble Gobble" << std::endl; }
	void fly(){std::cout << "Flies for a short duration" << std::endl;}
};
