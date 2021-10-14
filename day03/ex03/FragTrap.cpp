#include <string>
#include <iostream>
#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name):ClapTrap(name, 100, 50, 20) {
	std::cout << "FragTrap(name=\""<< name << "\") called " << std::endl;
}
FragTrap::~FragTrap() {
	std::cout << "~FragTrap() called by " << this->getName() << std::endl;
}

void FragTrap::highFivesGuys() {
	for (int i = 0; i < 5; i++) {
		std::cout << "FragTrap " << this->getName() << " requesting for high five" << std::endl;
	}
}
