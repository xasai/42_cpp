#pragma once
#include <ostream>
#ifndef __FIXED_H
# define __FIXED_H

class Fixed {
	public:
		
		Fixed(const int val);
		Fixed(const float val);

		Fixed();
		Fixed(const Fixed &obj);
		~Fixed(); 


		int  getRawBits() const;
		void setRawBits(int const raw);

		int	  toInt() const; 
		float toFloat(void) const;

		Fixed & operator = (const Fixed& obj);
		
	private:

		int _value;

		static const int _fract_bits = 8;
};

std::ostream& operator << (std::ostream &o, const Fixed &obj);

#endif 
