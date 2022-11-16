#pragma once
#include <string>
#include <list>

class Component {
protected:
	Component* parent_;

public:
	virtual ~Component() {}
	void SetParent(Component* parent) {
		this->parent_ = parent;
	}
	Component* GetParent() {
		return this->parent_;
	}

	virtual void Add(Component* component){}
	virtual void Remove(Component* component) {}
	virtual bool IsComposite() const {
		return false;
	}
	virtual std::string Operation() const = 0;
};

// Composite
class Folder : public Component {
protected:
	std::list<Component*> children;
public:
	std::string m_name;
	Folder(std::string name) : m_name(name) {}
	void Add(Component* component) override {
		this->children.push_back(component);
		component->SetParent(this);
	}
	void Remove(Component* component) override {
		children.remove(component);
	}
	bool IsComposite() const override {
		return true;
	}
	std::string Operation() const override {
		std::string result;
		for (const Component* c : children) {
			if (c == children.back()) {
				result += c->Operation();
			}
			else {
				result += c->Operation() + "+";
			}
		}
		return m_name+"(" + result + ")";
	}
};

// LEAF
class Message : public Component {
public:
	Message(std::string msg) : content(msg) {}
	std::string Operation() const override {
		return content;
	}
private:
	std::string content;
};
