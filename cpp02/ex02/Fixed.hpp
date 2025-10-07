#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include<iostream>
#include <cmath>
class Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed	(const Fixed &point);
		Fixed&	operator=(const Fixed &point);
		Fixed	operator+(const Fixed &point) const;
		Fixed	operator-(const Fixed &point) const;
		Fixed	operator*(const Fixed &point) const;
		Fixed	operator/(const Fixed &point) const;
		Fixed	operator++(int);
		Fixed&	operator++();
		Fixed	operator--(int);
		Fixed&	operator--();
		bool	operator>(const Fixed &point) const;
		bool	operator<(const Fixed &point) const;
		bool	operator>=(const Fixed &point) const;
		bool	operator<=(const Fixed &point) const;
		bool	operator==(const Fixed &point) const;
		bool	operator!=(const Fixed &point) const;
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		int		getRawBits(void);
		void	setRawBits(int const raw);
		float 	toFloat(void) const;
		int		toInt(void) const;
	
	private:
		int rawbits;
		static const int fract_bit = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& point);

#endif
