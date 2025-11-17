#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout <<"Default constructor called" <<std::endl;
	this->rawbits = 0;
}

Fixed::~Fixed(){
	std::cout <<" Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &point)
{
	std::cout<< "copy constructor called" << std::endl;
	this->rawbits = point.rawbits;
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