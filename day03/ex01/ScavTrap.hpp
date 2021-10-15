#pragma once
#ifndef __SCAV_TRAP_HPP
# define __SCAV_TRAP_HPP

#include <string> 
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap & c);
		ScavTrap operator = (const ScavTrap & c);
		~ScavTrap();

		void guardGate();

};

#endif // __SCAV_TRAP_HPP
