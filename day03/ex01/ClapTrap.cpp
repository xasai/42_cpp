#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):_name(name),_hp(10),_ep(10),_dmg(0) {
	std::cout << "ClapTrap(name=\""<< name << "\") called " << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int dmg):_name(name),_hp(hp),_ep(ep),_dmg(dmg) { 
	std::cout << "ClapTrap(name=\""<< name;
	std::cout << "\", hp=" << hp << ", ep=" << ep << ", dmg=" << dmg  << ") called";
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c):_name(c._name),_hp(c._hp),_ep(c._ep),_dmg(c._dmg) {
	std::cout << "ClapTrap(const ClapTrap & c) called" << std::endl;
}

ClapTrap ClapTrap::operator = (const ClapTrap &r) {
	std::cout << "ClapTrap ClapTrap::operator = (const ClapTrap & c) called" << std::endl;

	if (this == &r) {
		return *this;
	}
	setName(r.getName());
	setHp(r.getHp());
	setEp(r.getEp());
	setDmg(r.getDmg());
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "~ClapTrap() called by " << this->_name << std::endl;
}

std::string ClapTrap::getName() const {
	return _name;
}
int ClapTrap::getHp() const  {
	return _hp;
}
int ClapTrap::getEp() const  {
	return _ep;
}
int ClapTrap::getDmg() const  {
	return _dmg;
}

void ClapTrap::setName(std::string name){_name = name;}
void ClapTrap::setHp(int hp)  {_hp = hp;}
void ClapTrap::setEp(int ep)  {_ep = ep;}
void ClapTrap::setDmg(int dmg) {_dmg = dmg;}

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
