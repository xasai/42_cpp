#pragma once
#ifndef __DIAMOND_TRAP_HPP
# define __DIAMOND_TRAP_HPP

#include <string> 
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap & d);
		DiamondTrap operator = (const DiamondTrap & d);
		~DiamondTrap();
		void whoAmI();
		
		void attack(std::string const & target);

	private:
		std::string _name;
};

#endif // __DIAMOND_TRAP_HPP
