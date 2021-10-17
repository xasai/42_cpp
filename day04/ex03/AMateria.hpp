#pragma once
#ifndef __AMATERIA_HPP
# define __AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria {
    public:
        virtual ~AMateria();

        AMateria(std::string const & type);

        std::string const & getType(); 

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter & target);

    protected:
        AMateria();
        std::string _type;
};

#endif // __AMATERIA_HPP
