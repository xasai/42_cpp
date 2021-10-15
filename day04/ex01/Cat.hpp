#pragma once
#ifndef __CAT_HPP
# define __CAT_HPP

#include <iostream>
#include "Animal.hpp" 
#include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat():_type("Cat"), _voice("meow meow") {std::cout << "Cat() called"<< std::endl;};
		~Cat(){std::cout << "~Cat() called"<< std::endl;};

		void makeSound() const { std::cout << getType() << " " << getVoice() << std::endl; };

		const std::string getType() const { return _type; }
		const std::string getVoice() const { return _voice; }

	private:
		const std::string _type;
		const std::string _voice;
		Brain *_brain;
};

#endif // __CAT_HPP
