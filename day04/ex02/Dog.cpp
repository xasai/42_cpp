#include <iostream>
#include "Animal.hpp" 
#include "Dog.hpp"

Dog::Dog() {
	setName("noname");
	setType("Dog");
	setName("bark bark");
	std::cout << "Dog() called" << std::endl;
}

Dog::Dog(const std::string &name) {
	std::cout << "Dog(name=" << name << ") called" << std::endl;

	setName(name);
	setType("Dog");
	setName("bark bark");
	_brain = new Brain(name);
}

Dog::Dog(const Dog & d) {
	std::cout << "Dog(const Dog & c) called" << std::endl;
	setName(d._name);
	setType(d._type);
	setName(d._voice);
	delete _brain;
	this->_brain  = new Brain(*d._brain);
}

Dog Dog::operator = (const Dog & rhs) {
	std::cout << "Dog operator = called" << std::endl;
	if (this == &rhs)
		return *this;
	setName(rhs._name);
	setType(rhs._type);
	setVoice(rhs._voice);
	delete _brain;
	this->_brain  = new Brain(*rhs._brain);
	return *this;
}


Dog::~Dog() {
	std::cout << "~Dog() called" << std::endl;
	delete _brain;
}


void Dog::makeSound() const {
	std::cout << _voice << std::endl;
}

void Dog::checkInitIdea() const {
	_brain->checkInitIdea();
}
