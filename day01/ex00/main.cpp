#include <iostream>
#include <Zombie.hpp>


void randomChump(std::string name) {
	Zombie z = Zombie(name);
	z.announce();
}

Zombie* newZombie(std::string name) { 
	return new Zombie(name); 
}


void testStack() {
	std::cout << "main.testStack entered" << std::endl;
	
	//should die immidiatly
	randomChump("stack 1 randomChump");

	//should die after announce 
	Zombie z = Zombie("stack 2 Zombie");
	z.announce();
}

Zombie* testHeap() {
	std::cout << "main.testHeap entered" << std::endl;

	//should die immidiatly 
	Zombie* z =	newZombie("heap 1 newZombie Zombie");
	delete z;
	
	//should die in main after announce
	z = newZombie("heap 3 newZombie");
	
	return z;
}

int main() {
	testStack();
	std::cout << "main.testStack exited" << std::endl;
	Zombie *z = testHeap();
	std::cout << "main.testHeap exited" << std::endl;
	z->announce();
	delete z;
}
