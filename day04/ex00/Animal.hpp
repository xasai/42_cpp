#pragma once
#ifndef __ANIMAL_HPP
# define __ANIMAL_HPP

#include <iostream>

class Animal {
	public:
		Animal() {std::cout << "Animal() called" << std::endl;}
		virtual ~Animal() {std::cout << "~Animal() called" << std::endl;}

		virtual void makeSound() const {};

		virtual const std::string getType() const {return _type;};
		virtual const std::string getVoice() const {return _voice;};

	protected:
		std::string _type; 
		std::string _voice; 
};

#endif // __ANIMAL_HPP
