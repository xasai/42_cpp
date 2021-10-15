#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):_name(name),_hp(10),_ep(10),_dmg(0) {
	std::cout << "ClapTrap(name=\""<< name <<"\") called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c):_name(c._name),_hp(c._hp),_ep(c._ep),_dmg(c._dmg) {
	std::cout << "ClapTrap(const ClapTrap & c) called" << std::endl;
}

ClapTrap ClapTrap::operator = (const ClapTrap &r) {
	std::cout << "ClapTrap ClapTrap::operator = (const ClapTrap & c) called" << std::endl;

	if (this == &r) {
		return *this;
	}
	(void)_ep;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "~ClapTrap(std::string) called" << std::endl;
}

void ClapTrap::attack(std::string const & target) {
	std::cout <<  "ClapTrap " <<  this->_name << " attack " << target;
	std::cout << ", causing " << this->_dmg << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if ((this->_hp -= amount) < 0) {
		std::cout <<  "ClapTrap  " <<  this->_name << " takes " << amount <<  
			" points of damage! DIED :(" << std::endl;
	} else {
		std::cout <<  "ClapTrap " <<  this->_name << " takes " << amount <<  
			" points of damage! His HP: " << this->_hp << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {	
	this->_hp += amount;
	std::cout <<  "ClapTrap " <<  this->_name << " healed " << amount <<  " points of hp! His HP: " << this->_hp << std::endl;
}
