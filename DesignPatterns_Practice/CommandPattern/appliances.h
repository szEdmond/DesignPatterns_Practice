#pragma once
#include <iostream>
#include <string>

class Light {
public:
	Light(std::string lightName) : m_name(lightName) {}

	void on() {
		std::cout << m_name <<  " Light turned on" << std::endl;
	}
	void off() {
		std::cout << m_name << " Light turned off" << std::endl;
	}
	~Light() {}
private:
	std::string m_name;
};

//class GarageDoor {
//public:
//	void up() {
//		std::cout << "Rolling up the garage door" << std::endl;
//	}
//	void close() {
//		std::cout << "Closing garage door" << std::endl;
//	}
//	~GarageDoor() {}
//};
//
//class Fan {
//public:
//	const static int HIGH = 3;
//	const static int MEDIUM = 2;
//	const static int LOW = 1;
//	const static int OFF = 0;
//
//	Fan(std::string name) {
//		m_name = name;
//		m_speed = OFF;
//	}
//
//	void high() {
//		m_speed = HIGH;
//		std::cout << "fan high" << std::endl;
//	}
//	void medium() {
//		m_speed = MEDIUM;
//		std::cout << "fan medium" << std::endl;
//	}
//	void low() {
//		m_speed = LOW;
//		std::cout << "fan low" << std::endl;
//	}
//	void off() {
//		m_speed = OFF;
//		std::cout << "fan off" << std::endl;
//	}
//	int getSpeed() {
//		return m_speed;
//	}
//	~Fan() {}
//private:
//	std::string m_name;
//	int m_speed;
//
//};