#pragma once
#include "Turkey.h"
#include "Duck.h"

class TurkeyAdapter : public Duck{
public:
	TurkeyAdapter(Turkey* turkey) : m_turkey(turkey) {}
	void quack() { m_turkey->gobble(); }
	void fly() { m_turkey->fly(); }
private:
	Turkey* m_turkey;
};