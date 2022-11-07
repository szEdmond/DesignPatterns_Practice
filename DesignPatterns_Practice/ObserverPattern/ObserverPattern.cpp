#include<iostream>
#include<vector>
#include "WeatherData.h"
#include "Displays.h"
#include <crtdbg.h>

int main()
{
	{
		std::shared_ptr<WeatherData> wd = std::make_shared<WeatherData>();
		std::shared_ptr<CurrentConditionsDisplay> d1 = std::make_shared<CurrentConditionsDisplay>(wd);
		d1->addToWeatherData(d1);
		//wd->removeObserver(d1);
		//std::shared_ptr<CurrentConditionsDisplay> d2 =d1;
		std::cout << d1.use_count() << std::endl;
		//	CurrentConditionsDisplay *d2 = new CurrentConditionsDisplay(wd);
		wd->setMeasurements(69, 69, 69);
		wd->setMeasurements(10, 10, 10);
	}
	std::cout << "debug / check destructors :)";
	_CrtDumpMemoryLeaks();
}