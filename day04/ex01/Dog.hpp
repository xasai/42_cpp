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

		void makeSound() const;
		void  checkInitIdea();

	private:
		Dog();
		Brain *_brain;
};

#endif // __DOG_HPP
