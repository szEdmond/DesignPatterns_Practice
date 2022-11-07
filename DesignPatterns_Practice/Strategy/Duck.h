#pragma once
#include<iostream>
#include "Behaviours.h"

class Duck {
private:	
	FlyBehaviour* flyBehaviour;
	QuackBehaviour* quackBehaviour;

public:
	void swim() { std::cout << "I swim" << std::endl; }
	void performQuack() { quackBehaviour->quack(); }
	void performFly() { flyBehaviour->fly(); }

	void setFlyBehaviour(FlyBehaviour* fb) { 
		delete flyBehaviour; 
		flyBehaviour = fb; 
	}
	void setQuackBehaviour(QuackBehaviour* qb) { 
		delete quackBehaviour; 
		quackBehaviour = qb; 
	
	}

	~Duck() {
		std::cout << "i am being destroyed" << std::endl;

		delete flyBehaviour;
		delete quackBehaviour;
	}
};

class Mallard : public Duck {
public:
	Mallard() {
		setFlyBehaviour(new FlyWithWings);
		setQuackBehaviour(new Quack);
	}
	~Mallard() {
		std::cout << "i am being destroyed" << std::endl;
	}
};

class RocketDuck : public Duck {
public:
	RocketDuck() {
		setFlyBehaviour(new FlyRocketPowered);
		setQuackBehaviour(new MuteQuack);
	}
};