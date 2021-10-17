#include <iostream>
#include "Animal.hpp" 
#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat() called"<< std::endl;

	_name = "noname";
	_type = "Cat";
	_voice = "meow meow";
	_brain = new Brain("noname");
}
Cat::Cat(const std::string & name){
	std::cout << "Cat(name=" << name << ") called"<< std::endl;

	_name = name;
	_type = "Cat";
	_voice = "meow meow";
	_brain = new Brain(name);
}

Cat::Cat(const Cat & c) {
	std::cout << "Dog(const Cat & c) called" << std::endl;

	_name = c._name;
	_type = c._type;
	_voice = c._voice;
	delete _brain;
	_brain  = new Brain(*c._brain);
}

Cat Cat::operator = (const Cat & rhs) {
	std::cout << "Cat operator = called"<< std::endl;

	if (this == &rhs)
		return *this;

	_name = rhs._name;
	_type = rhs._type;
	_voice = rhs._voice;
	delete _brain;
	_brain  = new Brain(*rhs._brain);
	return *this;
}

Cat::~Cat() {
	std::cout << "~Cat() called"<< std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << _voice << std::endl;
}

void Cat::checkInitIdea() const {
	_brain->checkInitIdea();
}
