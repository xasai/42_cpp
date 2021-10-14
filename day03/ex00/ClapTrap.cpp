#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):_name(name),_hp(10),_ep(10),_dmg(0) {
	std::cout << "ClapTrap(name=\""<< name <<"\") called" << std::endl;
	(void)this->_ep; //mute unused;
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
