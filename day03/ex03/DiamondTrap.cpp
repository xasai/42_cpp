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
 
DiamondTrap::DiamondTrap(const DiamondTrap & d) : ClapTrap(d), _name(d._name) {
	std::cout << "~DiamondTrap() called by " << _name  << std::endl;
}

DiamondTrap DiamondTrap::operator = (const DiamondTrap & r) {
	std::cout << "~DiamondTrap() called by " << _name  << std::endl;

	if (this == &r) {
		return *this;
	}

	_name = r._name;

	setName(r.getName());
	setHp(r.getHp());
	setEp(r.getEp());
	setDmg(r.getDmg());

	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "Diamond trap's true name " << _name << std::endl;
	std::cout << "Diamond trap's parent's parent name " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(std::string const & target) {
	this->ScavTrap::attack(target);
}
