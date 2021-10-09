#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie default constructor called" << std::endl;
}

Zombie::Zombie(std::string name):_name(name) {
	std::cout << _name << " parametrized constructor called _name=" << name << std::endl;
}


Zombie::~Zombie() {
	std::cout << _name << " died" << std::endl;
}

void Zombie::announce() {
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
