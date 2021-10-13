#include <iostream>
#include <math.h>
#include "Fixed.hpp"

Fixed::Fixed():_value(0) {
	std::cout << "Fixed::Fixed() called" << std::endl;
}

Fixed::Fixed(const float val):_value(roundf(val * (1 << _fract_bits))) {
	std::cout << "Fixed::Fixed(float) called" << std::endl;
}

Fixed::Fixed(const int val):_value(val << _fract_bits) {
	std::cout << "Fixed::Fixed(int) called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) { 
	std::cout << "Fixed::Fixed(Fixed&) called" << std::endl;
	_value = obj._value; 
}

Fixed::~Fixed() {
	std::cout << "Fixed::~Fixed() called" << std::endl;
} 

int Fixed::getRawBits() const { return this->_value; }
void Fixed::setRawBits(int const raw) { _value = raw ;}

float Fixed::toFloat() const { 
	return (float)this->_value / (float)(1 << this->_fract_bits);
}

int Fixed::toInt() const { 
	return this->_value >> _fract_bits;
}

Fixed& Fixed::operator = (const Fixed& obj) { 
	std::cout << "Fixed::operator = (const Fixed& obj)" << std::endl;
	this->_value= obj.getRawBits();
	return *this;
}

std::ostream& operator << (std::ostream &o, const Fixed &obj) {
	return (o << obj.toFloat());
}
