#include <iostream>
#include "Animal.hpp" 
#include "Dog.hpp"

Dog::Dog():_type("Dog"), _voice("bark bark") {
	std::cout << "Dog() called"<< std::endl;
}

Dog::~Dog() {
	std::cout << "~Dog() called"<< std::endl;
}

/*
void makeSound() const { 
	std::cout << getType() << " " << getVoice() << std::endl; 
}
*/

const std::string Dog::getType() const { return _type; }
const std::string Dog::getVoice() const { return _voice; }
