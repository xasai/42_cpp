#pragma once 
#ifndef _WEAPON_HPP
# define _WEAPON_HPP

#include <string>

class Weapon {

	public:
		const std::string	&getType();
		void 				setType(std::string type);

		Weapon(std::string type);
		~Weapon();

	private:
		std::string _type;
};

#endif  // _WEAPON_HPP
