#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name):ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap(name=\""<< name << "\") called " << std::endl;
}
ScavTrap::~ScavTrap() {
	std::cout << "~ScavTrap() called by " << this->getName() << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName() << " gate keeper mode entered" << std::endl;
}
