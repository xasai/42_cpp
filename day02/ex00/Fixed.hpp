#pragma once
#include <ostream>
#ifndef __FIXED_H
# define __FIXED_H

class Fixed {
	public:
		
		Fixed();
		Fixed(const Fixed &obj);
		~Fixed(); 


		int  getRawBits() const;
		void setRawBits(int const raw);

		Fixed& operator = (const Fixed& obj);
		
	private:

		int _value;

		static const int _fract_bits = 8;
};

#endif 
