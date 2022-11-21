#include "State.h"

void LockedState::SideBtn() {
	std::cout << "phone unlocked" << std::endl;
	this->phone_->TransitionTo(new UnLockedState);
}
void LockedState::CameraBtn() {
	std::cout << "cannot acces, phone is locked" << std::endl;
}

void UnLockedState::SideBtn() {
	std::cout << "locked the phone" << std::endl;
	this->phone_->TransitionTo(new LockedState);
}
void UnLockedState::CameraBtn() {
	std::cout << "opening camera" << std::endl;
	this->phone_->TransitionTo(new CameraState);
}

void CameraState::SideBtn() {
	std::cout << "Taking a picture" << std::endl;
}
void CameraState::CameraBtn() {
	std::cout << "exiting camera app" << std::endl;
	this->phone_->TransitionTo(new UnLockedState);
}

