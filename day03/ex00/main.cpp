#include <iostream>
#include "ClapTrap.hpp" 

int main() {
	ClapTrap c("John");

	ClapTrap b = c;

	b.attack("bruh");
	c.attack("his son");
	c.beRepaired(1337);
	c.takeDamage(99999999);
}
