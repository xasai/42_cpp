#pragma once 
#ifndef _HUMAN_B_HPP
# define _HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
	public:
		void attack();
		void setWeapon(Weapon &weapon);

		HumanB(std::string name);
		~HumanB();
		
	private:

		std::string _name;
		Weapon 		*_weapon;
};

#endif  // _HUMAN_B_HPP
