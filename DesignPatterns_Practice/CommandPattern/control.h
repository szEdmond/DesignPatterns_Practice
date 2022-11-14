#pragma once
#include "command.h"

class RemoteControl {
	std::shared_ptr<Command> onCommands[7];
	std::shared_ptr<Command> offCommands[7];
	std::shared_ptr<Command> undoCommand;
	// use stack if multiple undo should be possible
public:
	RemoteControl(){
		std::shared_ptr<Command> noCommand = std::make_shared<NoCommand>();
		for (int i = 0; i < 7; i++) {
			onCommands[i] = noCommand;
			offCommands[i] = noCommand;
		}
		undoCommand = noCommand;
	}

	~RemoteControl() {}

	void setCommand(int slot,std::shared_ptr<Command> onCommand, std::shared_ptr<Command> offCommand) {
		onCommands[slot] = onCommand;
		offCommands[slot] = offCommand;
	}
	void onButtonWasPressed(int slot) {
		onCommands[slot]->execute();
		undoCommand = onCommands[slot];
	}
	void offButtonWasPressed(int slot) {
		offCommands[slot]->execute();
		undoCommand = offCommands[slot];
	}
	void undoButtonWasPressed() {
		undoCommand->undo();
	}
};
