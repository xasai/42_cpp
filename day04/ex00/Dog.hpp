#pragma once
#ifndef __DOG_HPP
# define __DOG_HPP

#include <iostream>
#include "Animal.hpp" 

class Dog: public Animal {
	public:
		Dog();
		~Dog();

		void makeSound();

		const std::string getType() const;
		const std::string getVoice() const;

	private:
		const std::string _type;
		const std::string _voice;
};

#endif // __DOG_HPP
