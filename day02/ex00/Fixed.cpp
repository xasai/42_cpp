#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed():_value(0) {
	std::cout << "Fixed::Fixed() called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) { 
	std::cout << "Fixed::Fixed(Fixed &obj) called" << std::endl;
	_value = obj._value; 
}

Fixed::~Fixed() {
	std::cout << "Fixed::~Fixed() called" << std::endl;
} 

Fixed& Fixed::operator = (const Fixed& obj) { 
	std::cout << "Fixed::operator = (const Fixed& obj)" << std::endl;
	this->_value= obj.getRawBits();
	return *this;
}

int Fixed::getRawBits() const { return _value; }
void Fixed::setRawBits(int const raw) { _value = raw ;}
