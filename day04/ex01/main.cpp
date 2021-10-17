#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


const int NN = 6;
std::string names[NN] = {"aaa", "bbb", "ccc'", "ddd", "eee", "fff"};

int main() {


	const int N = NN;
	Animal *animals[N];

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "                        Dogs" << std::endl;
	for (int i = 0; i < N / 2; i++) {
		animals[i] = new Dog(names[N % NN]);
		std::cout << std::endl;
	}

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "                        Cats" << std::endl;
	for (int i = N / 2; i < N; i++) {
		animals[i] = new Cat(names[NN % 6]);
		std::cout << std::endl;
	}
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "                        Deep copy copy-constructor" << std::endl << std::endl;

	Dog *dOrig  = static_cast<Dog*>(animals[0]);
	Dog dCopy(*dOrig);

	std::cout << std::endl;
	std::cout << "Original dog brain : " << std::endl;
	dOrig->checkInitIdea(); 

	std::cout << std::endl;
	std::cout << "Dog copy" << std::endl; 
	dCopy.checkInitIdea(); 

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "                        Deep copy assignation (operator =)" << std::endl << std::endl;

	Cat *cOrig  = static_cast<Cat*>(animals[N - 1]);
	Cat cCopy =  *cOrig; 

	std::cout << std::endl;
	std::cout << "Cat origin" << std::endl; 
	cOrig->checkInitIdea(); 

	std::cout << std::endl;
	std::cout << "Cat copy" << std::endl; 
	cCopy.checkInitIdea(); 

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "                        Destruct heap array" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << std::endl;
		delete animals[i];
	}
	std::cout << "----------------------------------------------------------------" << std::endl;
}
