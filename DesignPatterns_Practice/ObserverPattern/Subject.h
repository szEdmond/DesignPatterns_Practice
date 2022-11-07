#pragma once
#include "Observer.h"

class Subject {
public:
	virtual void notifyObservers() = 0;
};