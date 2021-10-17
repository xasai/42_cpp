#pragma once
#ifndef __DOG_HPP
# define __DOG_HPP

#include <iostream>
#include "Animal.hpp" 
#include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog(const std::string & name);
		Dog(const Dog & c);
		Dog operator = (const Dog & c);
		~Dog();

		void sleep() const;
		void makeSound() const;
		void checkInitIdea() const;

	private:
		Dog();
		Brain *_brain;
};

#endif // __DOG_HPP
