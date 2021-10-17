#pragma once
#ifndef __CURE_HPP
# define __CURE_HPP

#include "AMateria.hpp"

class Cure: virtual public AMateria {
    public:
        Cure();
        Cure(const Cure & i);
        Cure operator = (const Cure & i);
        ~Cure();

        AMateria* clone() const;
        void use(ICharacter & target);
};

#endif // __CURE_HPP
