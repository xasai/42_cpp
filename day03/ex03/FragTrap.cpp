#include <string>
#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap() called" << std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name, 100, 50, 20) {
	std::cout << "FragTrap(name=\""<< name << "\") called " << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "~FragTrap() called by " << getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap &c):ClapTrap(c) {
    std::cout << "FragTrap(const FragTrap & c) called" << std::endl;
}

FragTrap FragTrap::operator = (const FragTrap &r) {
    std::cout << "FragTrap FragTrap::operator = (const FragTrap & c) called" << std::endl;

    if (this == &r) {
        return *this;
    }
    setName(r.getName());
    setHp(r.getHp());
    setEp(r.getEp());
    setDmg(r.getDmg());

    return *this;
}

void FragTrap::attack(const std::string & target) {
	std::cout <<  "FragTrap " <<  getName() << " attack " << target 
				<< ", causing " << getDmg() << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << getName() << " request high five" << std::endl;
}
