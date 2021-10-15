#pragma once
#ifndef __SCAV_TRAP_HPP
# define __SCAV_TRAP_HPP

#include <string> 
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap & c);
		ScavTrap operator = (const ScavTrap & c);
		~ScavTrap();

		void guardGate();

		static const int HP = 100;
		static const int EP = 50;
		static const int DMG = 20;

	protected:
		ScavTrap();
};

#endif // __SCAV_TRAP_HPP
