#include "Singleton.h"
Singleton *Singleton::uniqueInstance = new Singleton();

int main() {
	// Singleton* s = new Singleton(); // private, can't access

	// same address
	Singleton* x = Singleton::getInstance();
	Singleton* y = Singleton::getInstance();

	Singleton::getInstance()->print();
	x->print();
	y->print();

	delete x;
}