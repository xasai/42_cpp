#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name):_name(name) {
	std::cout << "HumanB constructor parametrized called" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "HumanB destructor called" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
	std::cout << "HumanB set weapon " << weapon.getType() << std::endl;
}

void HumanB::attack() {
	if (_weapon)
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
	else 
		std::cout << _name << " has no weapon" << std::endl;
}
