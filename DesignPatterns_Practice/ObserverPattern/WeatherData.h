#pragma once
#include "Subject.h"
#include <vector>
#include "Observer.h"

class WeatherData : public Subject {
public:
	WeatherData(){}
	~WeatherData() {
		for (auto i : observers)
			i.reset();
		std::cout << "Destroy WeatherData" << std::endl;
	}
	void registerObserver(std::shared_ptr<Observer> o) {
		observers.push_back(o);
	}
	void removeObserver(std::weak_ptr<Observer > o) {
		observers.erase(std::remove_if(observers.begin(), observers.end(),
			[o](std::weak_ptr<Observer> i) { return i.lock() == o.lock(); }));
	}
	void notifyObservers() {
		for (std::weak_ptr<Observer> obs : observers)
			obs.lock()->update();
	}
	void mesurementsChanged() {
		notifyObservers();
	}
	void setMeasurements(float temp, float hum, float pres) {
		temperature = temp;
		humidity = hum;
		pressure = pres;
		mesurementsChanged();
	}

	float getTemperature() { return temperature;}
	float getHumidity() { return humidity; }
	float getPressure() { return pressure; }
private:
	std::vector<std::weak_ptr<Observer>>observers;
	float temperature = 0;
	float humidity = 0;
	float pressure = 0;
};