#pragma once
#ifndef __DOG_HPP
# define __DOG_HPP

#include <iostream>
#include "Animal.hpp" 
#include "Brain.hpp"

class Dog: public Animal {
	public:
		Dog():_type("Dog"), _voice("bark bark") {
			std::cout << "Dog() called"<< std::endl;
		}

		~Dog(){
			std::cout << "~Dog() called"<< std::endl;
			delete _brain;
		}

		void makeSound() const { std::cout << getType() << " " << getVoice() << std::endl; };

		const std::string getType() const { return _type; }
		const std::string getVoice() const { return _voice; }

	private:
		const std::string _type;
		const std::string _voice;
		Brain *_brain;
};

#endif // __DOG_HPP
