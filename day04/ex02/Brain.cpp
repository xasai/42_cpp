#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain() called" << std::endl;
}
Brain::Brain(const std::string & brainHandler) {
	std::cout << "Brain(brainHandler="<< brainHandler << ") called" << std::endl;
    ideas[0] = brainHandler + " init idea !";
}

Brain::Brain(const Brain & b) {
	std::cout << "Brain(const Brain & b) called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = b.ideas[i];
    }
}

Brain Brain::operator = (const Brain & rhs) {
	std::cout << "Brain operator = called" << std::endl;
	if (this == &rhs) {
		return *this;
    }
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = rhs.ideas[i];
    }
    return *this; 
}

void  Brain::checkInitIdea() {
    std::cout << "Brain address: " <<  this  << std::endl;
	std::cout << "idea: " << ideas[0] << " (" << ideas << ")" << std::endl;
}

Brain::~Brain() {
	std::cout << "~Brain() called"<< std::endl;
}
