#include <iostream>
#include <string>
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure():AMateria("cure") {
    std::cout << "Cure::Cure():AMateria(\"cure\") called" << std::endl;
}

Cure::Cure(const Cure & c) : AMateria(c._type) {
    std::cout << "Cure::Cure():AMateria(\"cure\") called" << std::endl;
}

Cure::~Cure() {
    std::cout << "Cure::~Cure() called"  << std::endl;
}

Cure Cure::operator = (const Cure & i) {
    std::cout << "Cure Cure::operator = (const Cure & i)" << std::endl;
    if (this == &i) {
        return *this;
    }
    return Cure(i);
}

AMateria *Cure::clone() const {
    return new Cure(*this);
}

void  Cure::use(ICharacter & target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
