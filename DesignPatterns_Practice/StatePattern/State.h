#pragma once
#include <iostream>
// ------------ STATE INTERFACE -------------------
class Phone;

class PhoneState {
protected:
	Phone* phone_;
public:
	virtual ~PhoneState() {}
	void setContext(Phone* ctx) {
		this->phone_ = ctx;
	}
	virtual void SideBtn() = 0;
	virtual void CameraBtn() = 0;
};

// ---------------- Context ------------------------

class Phone {
public:
	Phone(PhoneState* state) : state_(nullptr) {
		this->TransitionTo(state);
	}
	~Phone() { delete state_; }

	void TransitionTo(PhoneState* state) {
		if (this->state_ != nullptr)
			delete this->state_;
		this->state_ = state;
		this->state_->setContext(this);
	}

	void SideBtnPressed() {
		this->state_->SideBtn();
	}

	void CameraBtnPressed() {
		this->state_->CameraBtn();
	}

private:
	PhoneState* state_;
};

// ------------- CONCRETE STATES -------------------
class LockedState : public PhoneState {
public:
	void SideBtn();
	void CameraBtn();
};
class UnLockedState : public PhoneState {
	void SideBtn();
	void CameraBtn();
};

class CameraState : public PhoneState {
	void SideBtn();
	void CameraBtn();
};
