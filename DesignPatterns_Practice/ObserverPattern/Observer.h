#pragma once
#include <iostream>
class Observer {
public:
	virtual void update() = 0;
	virtual ~Observer() { std::cout << "Destroy Observer" << std::endl; }
};
