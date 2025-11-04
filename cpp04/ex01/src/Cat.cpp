#include "../include/Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	me = new Brain();
}

Cat::~Cat()
{
	delete me;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other): Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	me = new Brain(*other.me);
}

Cat& Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "\n😻 meow meow\n" << std::endl;
}

void Cat::idea(std::string id){me->addIdeas(id);}

void Cat::printBrain() const {me->printIdeas();}