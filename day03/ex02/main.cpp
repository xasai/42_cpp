#include <iostream>
#include "FragTrap.hpp" 

int main() {
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Assign cstruct" << std::endl;

	FragTrap a("'A'");
	FragTrap c("'C'");

	std::cout << "-------------------------------" << std::endl;
	std::cout << "Copy cstruct c" << std::endl;

	FragTrap cc(c);
	c.attack(" IAM 'C' copy");

	std::cout << "-------------------------------" << std::endl;
	std::cout << "Operator = c = a" << std::endl;
	c = a;
	c.attack("IAM 'A' from 'C'");

	a.attack(" IAM 'A' true");
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Destructors" << std::endl;
}
