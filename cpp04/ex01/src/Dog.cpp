#include "../include/Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	me = new Brain();
}

Dog::~Dog()
{
	delete me;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout <<"\n🐶 wof wof\n" << std::endl;
}

void Dog::idea(std::string id){me->addIdeas(id);}

void Dog::printBrain(){me->printIdeas();}