#pragma once
#include<iostream>

// --------------------------------------------------
// --------------- FlyBehaviours --------------------

class FlyBehaviour {
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehaviour {
public:
	void fly() { std::cout << "I can fly!" << std::endl; }
};

class FlyNoWay : public  FlyBehaviour {
public:
	void fly() {
		std::cout << "I cannot fly!" << std::endl;
	}
};

class FlyRocketPowered : public FlyBehaviour {
public:
	void fly() {
		std::cout << "I am rocket riding" << std::endl;
	}
};

// ---------------------------------------------------
// -------------- QuackBehaviours --------------------

class QuackBehaviour {
public:
	virtual void quack() = 0;
};

class Quack : public QuackBehaviour {
public:
	void quack() { std::cout << "I can Quack!" << std::endl; }
};

class Sqeak :public QuackBehaviour {
public:
	void quack() { std::cout << "I Sqeak!" << std::endl; }
};

class MuteQuack : public QuackBehaviour {
public:
	void quack() { std::cout << "Can't speak" << std::endl; }
};




