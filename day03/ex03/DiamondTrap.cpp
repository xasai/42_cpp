#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name+"_clap_name", FragTrap::HP, ScavTrap::EP, FragTrap::DMG),
	_name(name) {
	std::cout << "DiamondTrap(name=\""<< name << "\") called " << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "~DiamondTrap() called by " << _name  << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "Diamond trap's true name " << _name << std::endl;
	std::cout << "Diamond trap's parent's parent name " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(std::string const & target) {
	this->FragTrap::attack(target);
}
