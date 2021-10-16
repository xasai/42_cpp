#include <iostream>
#include "DiamondTrap.hpp" 

int main() {
	std::cout << "======================================" << std::endl;
	DiamondTrap d = DiamondTrap("Vladimir");

	d.whoAmI();
	d.attack("Putin");
	d.beRepaired(10);
	d.highFivesGuys();
	d.guardGate();
}
