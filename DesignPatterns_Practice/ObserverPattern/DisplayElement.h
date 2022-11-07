#pragma once
#include <iostream>

class DisplayElement {
public:
	virtual void display() = 0;
	virtual ~DisplayElement() { std::cout << "Destroy Display" << std::endl; }
};
