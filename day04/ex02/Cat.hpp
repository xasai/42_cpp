#pragma once
#ifndef __CAT_HPP
# define __CAT_HPP

#include <iostream>
#include "Animal.hpp" 
#include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat(const std::string & name);
		Cat(const Cat & c);
		Cat operator = (const Cat & c);
		~Cat();

		void sleep() const;
		void makeSound() const;
		void checkInitIdea() const;

	private:
		Cat();
		Brain *_brain;
};

#endif // __CAT_HPP
