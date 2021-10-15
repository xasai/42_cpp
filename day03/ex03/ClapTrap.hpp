#pragma once
#ifndef __CLAP_TRAP_HPP
# define __CLAP_TRAP_HPP

#include <string>

class ClapTrap {
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap & c);
		~ClapTrap();
		ClapTrap operator = (const ClapTrap & c);


		void attack(std::string const & target);	
		void takeDamage(unsigned int amount);	
		void beRepaired(unsigned int amount);	

	private:
		std::string _name;
		int _hp;
		int _ep;
		int _dmg;

	protected:
		ClapTrap();
		ClapTrap(std::string name, int hp, int ep, int dmg);

		std::string getName() const;
		int getHp() const;
		int getEp() const;
		int getDmg() const;

		void setName(std::string ame);
		void setHp(int hp);
		void setEp(int ep);
		void setDmg(int dmg);
};

#endif // __CLAP_TRAP_HPP
