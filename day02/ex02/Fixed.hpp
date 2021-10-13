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

		static Fixed& 	min(Fixed &a, Fixed &b);
		static const Fixed& 	min(const Fixed &a, const Fixed &b);

		static Fixed& 	max(Fixed &a, Fixed &b);
		static const Fixed& 	max(const Fixed &a, const Fixed &b);

		Fixed operator = (const Fixed& obj);
		Fixed operator + (const Fixed& obj) ;
		Fixed operator - (const Fixed& obj) ;
		Fixed operator * (const Fixed& obj) ;
		Fixed operator / (const Fixed& obj) ;

		bool operator < (const Fixed& obj) const;
		bool operator <= (const Fixed& obj) const;
		bool operator > (const Fixed& obj) const;
		bool operator >= (const Fixed& obj) const;
		bool operator == (const Fixed& obj) const;
		bool operator != (const Fixed& obj) const;

		Fixed& operator ++ ();
		Fixed operator ++ (int);

		Fixed& operator -- ();
		Fixed operator --(int);

	private:

		int _value;

		static const int _fract_bits = 8;
};

std::ostream& operator << (std::ostream &o, const Fixed &obj);

#endif 
