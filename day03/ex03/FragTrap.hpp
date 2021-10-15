#pragma once
#ifndef __FRAG_TRAP_HPP
# define __FRAG_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap & c);
		FragTrap operator = (const FragTrap & c);
		~FragTrap();
		
		void highFivesGuys();

		static const int HP = 100;
		static const int EP = 100;
		static const int DMG = 30;

	protected:
		FragTrap();
};

#endif //  __FRAG_TRAP_HPP



