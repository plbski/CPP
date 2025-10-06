#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include<iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed	(const Fixed &point);
		Fixed&	operator=(const Fixed &point);
		int		getRawBits();
		void	setRawBits(int const raw);
	
	private:
		int rawbits;
		static const int fract_bit = 8;
};

#endif
