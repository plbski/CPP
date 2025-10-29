#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "\nbliblablou\n" << std::endl;
}