#pragma once
#include <iostream>

struct Duck {
	virtual void quack() = 0;
	virtual void fly() = 0;
};

struct MallardDuck : public Duck {
	void quack() override {std::cout << "Quack" << std::endl;}
	void fly() override { std::cout << "I am flying" << std::endl; }
};
