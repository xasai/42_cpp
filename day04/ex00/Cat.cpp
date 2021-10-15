#include <iostream>
#include "Animal.hpp" 
#include "Cat.hpp"

Cat::Cat():_type("Cat"), _voice("meow meow") {
	std::cout << "Cat() called"<< std::endl;
}

Cat::~Cat() {
	std::cout << "~Cat() called"<< std::endl;
}

/*
void Cat::makeSound() const { 
	std::cout << getType() << " " << getVoice() << std::endl;
}
*/

const std::string Cat::getType() const { 
	return _type;

const std::string Cat::getVoice() const { 
	return _voice; 
}
