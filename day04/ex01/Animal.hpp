#pragma once
#ifndef __ANIMAL_HPP
# define __ANIMAL_HPP

#include <iostream>

class Animal {
	public:
		Animal();
		Animal(const Animal &r);
		Animal operator = (const Animal &r);
		virtual ~Animal();

		virtual void makeSound() const;

		std::string getType() const;
		std::string getVoice() const;

	protected:
		Animal(std::string name, std::string _type, std::string _voice);

		std::string _name;
		std::string _type; 
		std::string _voice; 
};

#endif // __ANIMAL_HPP
