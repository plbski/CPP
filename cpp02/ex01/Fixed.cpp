#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout <<"Default constructor called" <<std::endl;
	this->rawbits = 0;
}

Fixed::Fixed(int nb)
{
	std::cout <<"Int constructor called" <<std::endl;
	this->rawbits = nb << fract_bit;
}

Fixed::Fixed(float nb)
{
	std::cout <<"Float constructor called" <<std::endl;
	this->rawbits = roundf(nb * (1 << fract_bit));
}

Fixed::~Fixed(){
	std::cout <<"Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &point)
{
	std::cout<< "copy constructor called" << std::endl;
	*this = point;
}


Fixed& Fixed::operator=(const Fixed &point)
{
	std::cout<< "Copy assignement called"<< std::endl;
	if (this == &point)
		return (*this);
	this->rawbits = point.rawbits;
	return(*this);
}

int Fixed::getRawBits()
{
	std::cout<< "getRawbits function called"<< std::endl;
	return(this->rawbits);
}

void Fixed::setRawBits(int const raw)

{
	std::cout<< "setRawBits function called"<< std::endl;
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

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}