#include <iostream>
#include "ScavTrap.hpp" 

int main() {
	std::cout << "-------------------------------" << std::endl;

	ScavTrap a("'A'");
	a.attack("target");
	a.guardGate();
	a.beRepaired(10);

	std::cout << "-------------------------------" << std::endl;
	std::cout << "Destructors" << std::endl;
}
