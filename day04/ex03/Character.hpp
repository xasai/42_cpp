#pragma once
#ifndef __CHARACTER_HPP
# define __CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"

class Character: public ICharacter {
    public:
        Character(const std::string & name);
        Character(const Character & c);
        Character operator = (const Character & c);
        ~Character();

        std::string const & getName() const;
        void unequip(int idx);
        void equip(AMateria* m);
        void use(int idx, ICharacter& target);

    private:
        std::string _name;
        Character();
        AMateria *_materias[4];
};

#endif // __CHARACTER_HPP
