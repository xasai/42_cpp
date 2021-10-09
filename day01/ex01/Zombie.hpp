#pragma once
#ifndef _ZOMBIE_HPP
# define _ZOMBIE_HPP

#include <string>

class Zombie {

	public:

		void 	announce();
		
		Zombie();
		Zombie(std::string name);

		~Zombie();

	private: 

		std::string _name;
};

Zombie* zombieHorde(int n, std::string name);

#endif // _ZOMBIE_HPP
