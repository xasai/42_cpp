#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

class WrongAnimal {
	public:
		//WrongAnimal(){};
		const std::string getType() const {return "WrongAnimal";};
		void makeSound() const {std::cout << getType() << " ??? ??? " << std::endl;};
};

class WrongDog: public WrongAnimal {
	public:
		const std::string getType() const {return "WrongCat";};
		void makeSound() const {std::cout << getType() << " meow meow" << std::endl;};
};

class WrongCat: public WrongAnimal {
	public:
		const std::string getType() const {return "WrongDog";};
		void makeSound() const {std::cout << getType() << " bark bark"<< std::endl;};
};

int main() {

	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	d->makeSound(); //will output the cat sound!
	c->makeSound();
	meta->makeSound();

	delete meta;
	delete d;
	delete c;

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "                        Wrongs                                  " << std::endl;
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongAnimal* wrongDog = new WrongDog();
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	wrongDog->makeSound();
	delete wrongAnimal;
	delete wrongCat;
	delete wrongDog;
}
