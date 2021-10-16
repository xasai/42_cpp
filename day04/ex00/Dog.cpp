#include <iostream>
#include "Animal.hpp" 
#include "Dog.hpp"

Dog::Dog():Animal("Dog", "bark bark") {
	std::cout << "Dog() called"<< std::endl;
}

Dog::Dog(const Dog & c): Animal(c) {
	std::cout << "Dog(const Dog & c) called"<< std::endl;
}

Dog Dog::operator = (const Dog & rhs) {
	std::cout << "Dog operator = called"<< std::endl;
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	this->_voice = rhs._voice;
	return *this;
}

Dog::~Dog() {
	std::cout << "~Dog() called"<< std::endl;
}

void Dog::makeSound() const {
	std::cout << _voice << std::endl;
}
