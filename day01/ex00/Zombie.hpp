#pragma once
#ifndef _ZOMBIE_HPP
# define _ZOMBIE_HPP

#include <string>

class Zombie {

	public:

		void 	announce();
		
		Zombie(std::string name);
		~Zombie();

	private: 

		std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif // _ZOMBIE_HPP
