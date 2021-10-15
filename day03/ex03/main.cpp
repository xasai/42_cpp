#include <iostream>
#include "DiamondTrap.hpp" 

int main() {
	std::cout << "======================================" << std::endl;
	DiamondTrap d = DiamondTrap("FIRST");
	std::cout << "======================================" << std::endl;
	std::cout << "              Assign" << std::endl;
	DiamondTrap s = d;

	s.whoAmI();
}
