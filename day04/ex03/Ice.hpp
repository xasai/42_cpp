#pragma once
#ifndef __ICE_HPP
# define __ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria {
    public:
        Ice();
        Ice(const Ice & i);
        Ice operator = (const Ice & i);
        ~Ice();

        AMateria* clone() const;
        void use(ICharacter & target);
};

#endif // __ICE_HPP
