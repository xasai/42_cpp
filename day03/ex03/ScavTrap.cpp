#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap() called" << std::endl;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap(name=\""<< name << "\") called " << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "~ScavTrap() called by " << this->getName() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &c):ClapTrap(c) {
	std::cout << "ScavTrap(const ScavTrap & c) called" << std::endl;
}

ScavTrap ScavTrap::operator = (const ScavTrap &r) {
	std::cout << "ScavTrap ScavTrap::operator = (const ScavTrap & c) called" << std::endl;

	if (this == &r) {
		return *this;
	}
	setName(r.getName());
	setHp(r.getHp());
	setEp(r.getEp());
	setDmg(r.getDmg());

	return *this;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " gate keeper mode entered" << std::endl;
}
