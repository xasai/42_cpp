#include <string>
#include <iostream>
#include "Zombie.hpp"

void testZombieHorde() {
	std::cout << "main.testZombieHorde called" << std::endl;

	const int N = 5;

	Zombie* horde = zombieHorde(N, "zombie");
	std::cout << "main.zombieHorde exited" << std::endl;
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete[] horde;
}


int main() {
	testZombieHorde();
	std::cout << "main.testZombieHorde exited" << std::endl;
}
