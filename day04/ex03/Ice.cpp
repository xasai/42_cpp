#include <iostream>
#include <string>
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice():AMateria("ice") {
    std::cout << "Ice::Ice() called" << std::endl;
}

Ice::Ice(const Ice & i) {
    std::cout << "Ice::Ice(const Ice & i) called" << std::endl;
    _type = i._type;
}

Ice::~Ice() {
    std::cout << "Ice::~Ice() called"  << std::endl;
}

Ice Ice::operator = (const Ice & i) {
    std::cout << "Ice Ice::operator = (const Ice & i)" << std::endl;
    if (this == &i) {
        return *this;
    }
    _type = i._type;
    return *this;
}

AMateria *Ice::clone() const {
    return new Ice(*this);
}

void  Ice::use(ICharacter & target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
