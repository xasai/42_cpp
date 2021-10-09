#include <sstream>
#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) {
	std::cout << "main.zombieHorde called" << std::endl;

	Zombie* z = new Zombie[n];

	for (int i = 0; i < n; i++) {

		std::ostringstream ss;
		ss << "_" << i + 1;

		z[i] = Zombie(name + ss.str());
	}
	return z;
}

