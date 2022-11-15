#pragma once
#include <iostream>

struct Lights {
	void on() { std::cout << "Lights on" << std::endl; }
	void off() { std::cout << "Lights off" << std::endl; }
};

struct Projector {
	void on() { std::cout << "Projector on" << std::endl; } 
	void off() { std::cout << "Projector off" << std::endl; } 
};
struct Speaker {
	void on() { std::cout << "Speaker on" << std::endl; }
	void off() { std::cout << "Speaker off" << std::endl; }
	void setVolume(int vol) { m_volume = vol; }
private:
	int m_volume = 0;
};