#pragma once
#include "gadgets.h"

class HomeTheatreController {
public:
	HomeTheatreController(Projector projector, Speaker speaker, Lights light)
		: m_projector(projector), m_speakers(speaker), m_light(light) {}
	void watchMovie(std::string movie) {
		m_light.off();
		m_projector.on();
		m_speakers.on();
		m_speakers.setVolume(25);
		std::cout << "playing " << movie << std::endl;
	}
	void turnOff() {
		m_light.on();
		m_projector.off();
		m_speakers.off();
	}
private:
	Projector m_projector;
	Lights m_light;
	Speaker m_speakers;

	
};