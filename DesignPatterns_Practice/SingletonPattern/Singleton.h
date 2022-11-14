#pragma once
#include <iostream>

// EAGER CREATION
// instance created on class loading
class Singleton {
	static Singleton* uniqueInstance; // declared in CPP
	Singleton() {  };
public:
	static Singleton* getInstance() {
		return uniqueInstance;
	}
	void print() {
		std::cout << "singleton print" << std::endl;
	}
};


// Double-Checked -> thread safe & fast
// ---------------------------
//
//
//


// -------------------------------
// NOT THREAD SAFE - LAZY CREATION 
 
//class Singleton {
//	static Singleton* uniqueInstance;
//public:
//	static Singleton* getInstance() {
//		if (uniqueInstance == nullptr) {
//			uniqueInstance = new Singleton();
//		}
//		return uniqueInstance;
//	}
//private:
//	Singleton() {};
//}; 