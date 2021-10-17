#pragma once
#ifndef __ANIMAL_HPP
# define __ANIMAL_HPP

#include <iostream>

class Animal {
	public:

		virtual ~Animal();

		virtual void makeSound() const = 0; 

		std::string getName() const;
		std::string getType() const;
		std::string getVoice() const;

		void setName(std::string name);
		void setType(std::string type);
		void setVoice(std::string voice);

	protected:
		std::string _name;
		std::string _type; 
		std::string _voice; 
};

#endif // __ANIMAL_HPP
