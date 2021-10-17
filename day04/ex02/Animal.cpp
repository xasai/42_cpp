#include <string>
#include <iostream>
#include "Animal.hpp"

Animal::~Animal() {}

std::string Animal::getName() const {return _name;}
std::string Animal::getType() const {return _type;}
std::string Animal::getVoice() const { return _voice; }

void  Animal::setName(std::string name) {_name = name;}
void  Animal::setType(std::string type) {_type = type;}
void  Animal::setVoice(std::string voice) {_voice = voice;}
