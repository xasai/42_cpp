#include <string>
#include <iostream>
#include "Character.hpp"


Character::Character() {
    std::cout << "Character::Character() called" << std::endl;
    for (int i = 0; i < 4; i++) 
        _materias[i] = NULL;
}

Character::Character(const std::string & name) {
    std::cout << "Character::Character(const std::string name=\"" << name << "\")called" << std::endl;
    _name = name;
}


Character::Character(const Character & c) {
    std::cout << "Character::Character(const Character & c):Character(<<" << c.getName() << " called " << std::endl;
    _name = c.getName();
    for (int i = 0; i < 4; i++) {
        this->_materias[i] = c._materias[i]->clone();
    }
}


Character::~Character() {
    std::cout << "Character::~Character() called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_materias[i])
			delete _materias[i];
	}
}

Character Character::operator = (const Character & rhs) {
    std::cout << "Character Character::operator = (const Character & rhs) called" << std::endl;
    if (this == &rhs) {
        return *this;
    }
    _name = rhs.getName();
    for (int i = 0; i < 4; i++) {
        this->_materias[i] = rhs._materias[i]->clone();
    }
    return *this;
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::unequip(int idx) { 
    _materias[idx] = NULL;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++ ) {
        if (_materias[i] == NULL) {
            _materias[i]  = m;
            return ;
        }
    }
    std::cout << "All materias slots is busy" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
    if (_materias[idx] == NULL) {
        std::cout << "Materia with idx " << idx << " does not equiped" << std::endl;
    } else {
        _materias[idx]->use(target);
    }
}

