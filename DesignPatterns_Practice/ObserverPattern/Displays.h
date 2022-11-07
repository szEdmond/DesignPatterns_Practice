#pragma once
#include <iostream>
#include "Observer.h"
#include "DisplayElement.h"
#include "WeatherData.h"

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
private:
	float temperature =0;
	float humidity =0;
	std::shared_ptr<WeatherData> weatherData;

public:
	CurrentConditionsDisplay(std::shared_ptr<WeatherData> wd) {
		weatherData = wd;
		//weatherData->registerObserver(std::static_pointer_cast<CurrentConditionsDisplay>(this->shared_from_this()));
	}
	void addToWeatherData(std::shared_ptr<CurrentConditionsDisplay> ptr) {
		weatherData->registerObserver(ptr);
	}

	~CurrentConditionsDisplay() {}

	void update() {
		temperature = weatherData->getTemperature();
		humidity = weatherData->getHumidity();
		display();
	}
	void display() {
		std::cout << "Current conditions: " << temperature << "C degrees and " << humidity << "% humidity" << std::endl;
	}
};

