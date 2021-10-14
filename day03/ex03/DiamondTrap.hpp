#pragma once
#ifndef __DIAMOND_TRAP_HPP
# define __DIAMOND_TRAP_HPP

#include <string> 
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	public:
		DiamondTrap(std::string name);
		~DiamondTrap();
		void whoAmI();
		
		void attack(std::string const & target);

		std::string getName() { return this->_name; };

	private:
		std::string _name;
};

#endif // __DIAMOND_TRAP_HPP
