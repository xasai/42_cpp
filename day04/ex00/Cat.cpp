#include <iostream>
#include "Animal.hpp" 
#include "Cat.hpp"

Cat::Cat():Animal("Cat", "meow meow") {
	std::cout << "Cat() called"<< std::endl;
}

Cat::Cat(const Cat & c): Animal(c) {
	std::cout << "Cat(const Cat & c) called"<< std::endl;
}

Cat Cat::operator = (const Cat & rhs) {
	std::cout << "Cat operator = called"<< std::endl;
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	this->_voice = rhs._voice;
	return *this;
}

void Cat::makeSound() const {
	std::cout << _voice << std::endl;
}

Cat::~Cat() {
	std::cout << "~Cat() called"<< std::endl;
}
