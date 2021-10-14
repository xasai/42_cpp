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

	protected:
		ClapTrap(std::string name, int hp, int ep, int dmg);
		ClapTrap(){};

		int getHp() {return this->_hp;};
		int getEp() {return this->_ep;};
		int getDmg() {return this->_dmg;};
		std::string getName() {return this->_name;};
};

#endif // __CLAP_TRAP_HPP
