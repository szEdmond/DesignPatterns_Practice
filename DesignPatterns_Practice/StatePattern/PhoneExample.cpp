#include "State.h"

int main() {
	Phone* phone = new Phone(new LockedState);
	phone->SideBtnPressed();
	phone->SideBtnPressed();
	phone->SideBtnPressed();
	phone->CameraBtnPressed();
	phone->SideBtnPressed();
	phone->CameraBtnPressed();
	phone->SideBtnPressed();


	delete phone;
}