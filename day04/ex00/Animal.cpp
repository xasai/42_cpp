#include <string>
#include <iostream>
#include "Animal.hpp"

Animal::Animal() : _type("???"), _voice("??? ???") {
    std::cout << "Animal() called" << std::endl;
}

Animal::Animal(std::string type, std::string voice) : _type(type), _voice(voice) {
    std::cout << "Animal(std::string type, std::string voice)" << std::endl;
}

Animal::~Animal() {
    std::cout << "~Animal() called" << std::endl;
}

Animal::Animal(const Animal & a) {
    std::cout << "Animal(const Animal & a) called" << std::endl;
    *this = a;
}

Animal Animal::operator = (const Animal & rhs) {
    std::cout << "Animal::operator = called" << std::endl;
    if (this == &rhs)
        return *this;

    _type = rhs._type;
    _voice = rhs._voice;
    return *this;
}
void Animal::makeSound() const {
    std::cout << " UNKNONW ANIMAL VOICE " << std::endl;
}

std::string Animal::getType() const {
    return _type;
}

std::string Animal::getVoice() const {
    return _voice;
}
