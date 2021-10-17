#include <iostream>
#include "Animal.hpp" 
#include "Cat.hpp"

Cat::Cat():Animal("noname", "Cat", "meow meow") {
	std::cout << "Cat() called"<< std::endl;
}
Cat::Cat(const std::string & name):Animal(name, "Cat", "meow meow") {
	std::cout << "Cat(name=" << name << ") called"<< std::endl;
	_brain = new Brain(name);
}

Cat::Cat(const Cat & c):Animal(c._name, c._type, c._voice) { //  
	std::cout << "Dog(const Cat & c) called" << std::endl;
	this->_brain  = new Brain(*c._brain);
}

Cat Cat::operator = (const Cat & rhs) {
	std::cout << "Cat operator = called"<< std::endl;
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	this->_voice = rhs._voice;
	this->_brain  = rhs._brain;
	return *this;
}

Cat::~Cat() {
	std::cout << "~Cat() called"<< std::endl;
	delete _brain;
}



void Cat::makeSound() const {
	std::cout << _voice << std::endl;
}

void Cat::checkInitIdea() {
	_brain->checkInitIdea();
}
