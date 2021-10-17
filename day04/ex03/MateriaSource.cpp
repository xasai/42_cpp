#include <iostream>
#include "MateriaSource.hpp"


MateriaSource::MateriaSource() {
    std::cout << "MateriaSource::MateriaSource() called" << std::endl;
    _materiaSourceIdx = 0;
}

MateriaSource::MateriaSource(const MateriaSource & m) {
    std::cout << "MateriaSource::MateriaSource(const MateriaSource & m)" << std::endl;

    for (int i = 0; i < _materiaSourceIdx; i++) {
       _materiaSources[i] = m._materiaSources[i]->clone();
    }
    _materiaSourceIdx = m._materiaSourceIdx;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource::~MateriaSource() called" << std::endl;
    for (int i = 0; i < _materiaSourceIdx; i++) {
        delete _materiaSources[i];
    }
}

MateriaSource MateriaSource::operator = (const MateriaSource & rhs) {
    std::cout << "MateriaSource MateriaSource::operator = (const MateriaSource & m)" << std::endl;

    if (this == &rhs) {
        return *this;
    }

    for (int i = 0; i < _materiaSourceIdx; i++) {
       _materiaSources[i] = rhs._materiaSources[i]->clone();
    }
    _materiaSourceIdx = rhs._materiaSourceIdx;
    return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
    if (_materiaSourceIdx >= _nbMaxMateriaSources)
        return ;
    _materiaSources[_materiaSourceIdx] = m;
    _materiaSourceIdx++;
}

AMateria* MateriaSource::createMateria(std::string const & type){
    std::cout << "AMateria* MateriaSource::createMateria(std::string const & type) called" << std::endl;

    for (int i = 0; i < _materiaSourceIdx; i++) {
        if  (type == _materiaSources[i]->getType()) {
            std::cout << type << ": materia found" << std::endl;
            return _materiaSources[i]->clone();
        }
    }

    std::cout << type << ": materia not learned" << std::endl;
    return NULL;
}
