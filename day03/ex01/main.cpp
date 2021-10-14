#include <iostream>
#include "ScavTrap.hpp" 

int main() {
	ScavTrap c("John");

	c.attack("his son");
	c.beRepaired(1337);
	c.takeDamage(99999999);
	c.guardGate();
}
