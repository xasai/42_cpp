#include <string> 
#include <iostream> 
#include "Weapon.hpp"

Weapon::Weapon(std::string type):_type(type) {
	std::cout << "Weapon default constructor called _type=" << type << std::endl;
}

Weapon::~Weapon() {
	std::cout << "Weapon " << this->_type << " default destructor called" << std::endl;
}

const std::string& Weapon::getType(){
	return this->_type;
}

void Weapon::setType(std::string type) {
	this->_type = type;
}
