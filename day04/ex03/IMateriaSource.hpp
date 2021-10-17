#pragma once
#ifndef __IMATERIA_SOURCE_HPP
# define __IMATERIA_SOURCE_HPP
#include <string>
#include "AMateria.hpp"

class IMateriaSource {
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria* m) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif //__IMATERIA_SOURCE_HPP
