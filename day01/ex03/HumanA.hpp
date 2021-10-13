#pragma once 
#ifndef _HUMAN_A_HPP
#define _HUMAN_A_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
	public:

		void attack();

		HumanA(std::string name, Weapon &weapon);
		~HumanA();

	private:

		std::string _name;
		Weapon 		&_weapon;
};

#endif  // _HUMAN_A_HPP
