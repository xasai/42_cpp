#include <iostream>
#include "Animal.hpp" 
#include "Dog.hpp"

Dog::Dog():Animal("noname", "Dog", "bark bark") {
	std::cout << "Dog() called" << std::endl;
}

Dog::Dog(const std::string &name):Animal(name, "Dog", "bark bark") {
	std::cout << "Dog(name=" << name << ") called" << std::endl;
	_brain = new Brain(name);
}

Dog::Dog(const Dog & d):Animal(d._name, d._type, d._voice) { //  
	std::cout << "Dog(const Dog & c) called" << std::endl;
	this->_brain  = new Brain(*d._brain);
}

Dog Dog::operator = (const Dog & rhs) {
	std::cout << "Dog operator = called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	this->_voice = rhs._voice;
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

void Dog::checkInitIdea() {
	_brain->checkInitIdea();
}
