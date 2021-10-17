#pragma once
#ifndef __MATERIA_SOURCE_HPP
# define __MATERIA_SOURCE_HPP
#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource {
    public:
        MateriaSource();
        MateriaSource(const MateriaSource & m);
        MateriaSource operator = (const MateriaSource & m);

        ~MateriaSource();

        void learnMateria(AMateria* m); 

        AMateria* createMateria(std::string const & type);


    private: 
        static const int _nbMaxMateriaSources = 4;

        int _materiaSourceIdx;
        AMateria *_materiaSources[_nbMaxMateriaSources];

};

#endif //__MATERIA_SOURCE_HPP
