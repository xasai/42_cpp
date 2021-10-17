#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {_type = "non";}

AMateria::~AMateria() {}

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "AMateria(std::string const & type) : _type(\""<<type<<"\") called" << std::endl;
}

std::string const & AMateria::getType() { return _type; }

void AMateria::use(ICharacter & target) {
    std::cout << "VIRTUAL AMateria::use CALLED ! target: " << target.getName() << std::endl;
}
