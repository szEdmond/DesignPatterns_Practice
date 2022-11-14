#pragma once
#include "appliances.h"
#include <vector>

class Command{
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~Command() {}
};
// ----------------------------------------
class NoCommand : public Command {
public:
	void execute() override {}
	void undo() override{}
	~NoCommand() {}
};

// ----------------------------------------

class MacroCommand : public Command{
public:
	MacroCommand(std::vector<std::shared_ptr<Command>> commands) {
		for (int i = 0; i < commands.size(); i++) {
			m_commands.push_back(commands[i]);
		}
	}
	void execute() override {
		for (auto command : m_commands) {
			command->execute();
		}
	}
	void undo() {
		for (auto command : m_commands) {
			command->undo();
		}
	}
	~MacroCommand() {}
private:
	std::vector<std::shared_ptr<Command>> m_commands;
};
// -------------------------------------------------
class LightOnCommand : public Command {
public:
	LightOnCommand(std::shared_ptr<Light> light) {
		m_light = light;
	}
	void execute() override {
		m_light.lock()->on();
	}
	void undo() {
		m_light.lock()->off();
	}
	~LightOnCommand() {	}
private:
	std::weak_ptr<Light> m_light;
};

class LightOffCommand : public Command {
	std::weak_ptr<Light> m_light;
public:
	LightOffCommand(std::shared_ptr<Light> light) {
		m_light = light;	
	}
	void execute() override {
		m_light.lock()->off();
	}
	void undo() {
		m_light.lock()->on();
	}
	~LightOffCommand() {}
};
// ---------------------------------------------
//
//class GarageDoorOnCommand : public Command {
//public:
//	GarageDoorOnCommand(GarageDoor* garageDoor) {
//		m_garageDoor = garageDoor;
//	}
//	void execute() override {
//		m_garageDoor->up();
//	}
//	void undo() {
//		m_garageDoor->close();
//	}
//	~GarageDoorOnCommand() {}
//private:
//	GarageDoor* m_garageDoor;
//};
//class GarageDoorOffCommand : public Command {
//public:
//	GarageDoorOffCommand(GarageDoor* garageDoor) {
//		m_garageDoor = garageDoor;
//	}
//	void execute() override {
//		m_garageDoor->close();
//	}
//	void undo() {
//		m_garageDoor->up();
//	}
//	~GarageDoorOffCommand() {}
//private:
//	GarageDoor* m_garageDoor;
//};
//// ----------------------------------------
//class FanHighCommand : public Command {
//public:
//	FanHighCommand(Fan* fan) {
//		m_fan = fan;
//	}
//	void execute() override {
//		m_prevSpeed = m_fan->getSpeed();
//		m_fan->high();
//	}
//	void undo() override {
//		if (m_prevSpeed == m_fan->HIGH)
//			m_fan->high();
//		else if (m_prevSpeed == m_fan->MEDIUM) 
//			m_fan->medium();
//		else if (m_prevSpeed == m_fan->LOW) 
//			m_fan->low();
//		else if (m_prevSpeed == m_fan->OFF)
//			m_fan->off();
//	} 
//	~FanHighCommand() {}
//private:
//	Fan* m_fan;
//	int m_prevSpeed;
//};
//
//
//class FanOffCommand : public Command {
//public:
//	FanOffCommand(Fan* fan) {
//		m_fan = fan;
//	}
//	void execute() override {
//		m_prevSpeed = m_fan->getSpeed();
//		m_fan->off();
//	}
//	void undo() override {
//		if (m_prevSpeed == m_fan->HIGH)
//			m_fan->high();
//		else if (m_prevSpeed == m_fan->MEDIUM) 
//			m_fan->medium();
//		else if (m_prevSpeed == m_fan->LOW) 
//			m_fan->low();
//		else if (m_prevSpeed == m_fan->OFF)
//			m_fan->off();
//	} 
//	~FanOffCommand() {}
//private:
//	Fan* m_fan;
//	int m_prevSpeed;
//};

