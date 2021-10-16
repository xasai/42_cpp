#pragma once
#ifndef __DOG_HPP
# define __DOG_HPP

#include <iostream>
#include "Animal.hpp" 

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog & c);
		Dog operator = (const Dog & c);
		~Dog();

		void makeSound() const;
};



#endif // __DOG_HPP
