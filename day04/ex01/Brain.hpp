#pragma once
#ifndef __BRAIN_HPP
# define  __BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	public:
		Brain() {std::cout << "Brain() called" << std::endl;}
		~Brain() {std::cout << "~Brain() called" << std::endl;}

		std::string ideas[100];
};

#endif // __BRAIN_HPP
