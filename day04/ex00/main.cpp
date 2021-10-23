#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

class WrongAnimal {
	public:
		const std::string getType() const {
			return "???";
		}
		void makeSound() const {
			std::cout << getType() << " ??? ??? " << std::endl;
		}
};

class WrongCat: public WrongAnimal {
	public:
		const std::string getType() const {
			return "WrongCat";
		}
		void makeSound() const {
			std::cout << getType() << " bark bark"<< std::endl;
		}
};

int main() {


	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "                        Unknown Animal" << std::endl;
	const Animal* meta = new Animal();
	std::cout << meta->getType() << " says: ";
	meta->makeSound();
	delete meta;

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "                        Dog" << std::endl;
	const Animal* d = new Dog();
	std::cout << d->getType() << " says: ";
	d->makeSound();
	delete d;

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "                        Cat" << std::endl;
	const Animal* c = new Cat();
	std::cout << c->getType() << " says: ";
	c->makeSound();
	delete c;

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "                        Wrongs                                  " << std::endl;
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	delete wrongAnimal;
	delete wrongCat;
}
