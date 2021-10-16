#pragma once
#ifndef __CAT_HPP
# define __CAT_HPP

#include <iostream>
#include "Animal.hpp" 

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat & c);
		Cat operator = (const Cat & c);
		~Cat();

		void makeSound() const;
};

#endif // __CAT_HPP
