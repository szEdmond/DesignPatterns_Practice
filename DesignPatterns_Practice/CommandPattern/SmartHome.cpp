#ifdef _DEBUG
#define MYDEBUG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define MYDEBUG_NEW
#endif // _DEBUG
#include "crtdbg.h"
#ifdef _DEBUG
#define new MYDEBUG_NEW
#endif

#include <iostream>
#include "control.h"

int main()
{
	{
		std::shared_ptr<RemoteControl> remote  = std::make_shared<RemoteControl>();

		std::shared_ptr<Light> kitchenLight = std::make_shared<Light>("Kitchen");
		std::shared_ptr<Light> bedRoomLight = std::make_shared<Light>("BedRoom");


		std::shared_ptr<LightOnCommand> kitchenLightOn = std::make_shared<LightOnCommand>(kitchenLight);
		std::shared_ptr<LightOffCommand> kitchenLightOff = std::make_shared<LightOffCommand>(kitchenLight);
		std::shared_ptr<LightOnCommand> bedRoomLightOn = std::make_shared<LightOnCommand>(bedRoomLight);
		std::shared_ptr<LightOffCommand> bedRoomLightOff = std::make_shared<LightOffCommand>(bedRoomLight);

		////GarageDoor* garageDoor = new GarageDoor();

		////GarageDoorOnCommand* garageOpen = new GarageDoorOnCommand(garageDoor);
		////GarageDoorOffCommand* garageClose = new GarageDoorOffCommand(garageDoor);

		////Fan* fan = new Fan("BedRoomFan");
		////FanOffCommand* fanOff = new FanOffCommand(fan);
		////FanHighCommand* fanHigh = new FanHighCommand(fan);


		std::vector<std::shared_ptr<Command>> everythingOn { kitchenLightOn, bedRoomLightOn };
		std::vector<std::shared_ptr<Command>> everythingOff { kitchenLightOff, bedRoomLightOff };

		std::shared_ptr<MacroCommand> onAll = std::make_shared<MacroCommand>(everythingOn);
		std::shared_ptr<MacroCommand> offAll = std::make_shared<MacroCommand>(everythingOff);


		remote->setCommand(0, kitchenLightOn, kitchenLightOff);
		remote->setCommand(1, bedRoomLightOn, bedRoomLightOff);
		////remote->setCommand(2, garageOpen, garageClose);
		////remote->setCommand(3, fanHigh, fanOff);
		remote->setCommand(4, onAll, offAll);

		remote->onButtonWasPressed(4);
		remote->offButtonWasPressed(4);
		remote->undoButtonWasPressed();

	}
	_CrtDumpMemoryLeaks();
	/*remote->onButtonWasPressed(0);
	remote->offButtonWasPressed(0);
	remote->undoButtonWasPressed();

	remote->onButtonWasPressed(1);
	remote->offButtonWasPressed(1);

	remote->onButtonWasPressed(2);
	remote->offButtonWasPressed(2);

	remote->onButtonWasPressed(3);
	remote->offButtonWasPressed(3);
	remote->undoButtonWasPressed();*/
}