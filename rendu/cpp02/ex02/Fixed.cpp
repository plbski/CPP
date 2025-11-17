#include "Fixed.hpp"
 //constructor
Fixed::Fixed()
{
	this->rawbits = 0;
}

Fixed::Fixed(int nb)
{
	this->rawbits = nb << fract_bit;
}

Fixed::Fixed(float nb)
{
	this->rawbits = roundf(nb * (1 << fract_bit));
}
Fixed::Fixed(const Fixed &point)
{
	*this = point;
}


Fixed::~Fixed(){};

//access
int Fixed::getRawBits()
{
	return(this->rawbits);
}

void Fixed::setRawBits(int const raw)

{
	this->rawbits = raw;
}

int Fixed::toInt(void) const
{
	return(rawbits >> fract_bit);
}

float Fixed::toFloat(void) const
{
	return((float)rawbits / (1 << fract_bit));
}

//operation
Fixed& Fixed::operator=(const Fixed &point)
{
	if (this == &point)
		return (*this);
	this->rawbits = point.rawbits;
	return(*this);
}

Fixed Fixed::operator+(const Fixed &point) const {return (this->toFloat() + point.toFloat());}

Fixed Fixed::operator-(const Fixed &point) const {return (this->toFloat() - point.toFloat());}

Fixed Fixed::operator*(const Fixed &point) const {return (this->toFloat() * point.toFloat());}

Fixed Fixed::operator/(const Fixed &point) const {return (this->toFloat() / point.toFloat());}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	rawbits ++;
	return(tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	rawbits --;
	return(tmp);
}

Fixed& Fixed::operator++()
{
	rawbits ++;
	return(*this);
}

Fixed& Fixed::operator--()
{
	rawbits --;
	return(*this);
}

bool	Fixed::operator>(const Fixed &point) const {return (this->rawbits > point.rawbits);}

bool	Fixed::operator<(const Fixed &point) const {return (this->rawbits < point.rawbits);}

bool	Fixed::operator>=(const Fixed &point) const {return (this->rawbits >= point.rawbits);}

bool	Fixed::operator<=(const Fixed &point) const {return (this->rawbits <= point.rawbits);}

bool	Fixed::operator==(const Fixed &point) const {return (this->rawbits == point.rawbits);}

bool	Fixed::operator!=(const Fixed &point) const {return (this->rawbits != point.rawbits);}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return(a);
	return(b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return(a);
	return(b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return(a);
	return(b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return(a);
	return(b);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
