#pragma once
#ifndef __CAT_HPP
# define __CAT_HPP

#include <iostream>
#include "Animal.hpp" 

class Cat : public Animal {
	public:
		Cat();
		~Cat();

		void makeSound() const;

		const std::string getType() const;
		const std::string getVoice() const;

	private:
		const std::string _type;
		const std::string _voice;
};

#endif // __CAT_HPP
