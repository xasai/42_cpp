#pragma once
#ifndef __CLAP_TRAP_HPP
# define __CLAP_TRAP_HPP

#include <string>

class ClapTrap {
	public:
		ClapTrap(std::string name);
		~ClapTrap(); 

		void attack(std::string const & target);	
		void takeDamage(unsigned int amount);	
		void beRepaired(unsigned int amount);	

	private:
		std::string _name;
		int _hp;
		int _ep;
		int _dmg;
};

#endif // __CLAP_TRAP_HPP
