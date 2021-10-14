#pragma once
#ifndef __FRAG_TRAP_HPP
# define __FRAG_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(std::string name);
		~FragTrap();
		
		void highFivesGuys();
};

#endif //  __FRAG_TRAP_HPP

