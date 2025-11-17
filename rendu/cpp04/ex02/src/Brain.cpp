#include "../include/Brain.hpp"
#include "../include/Animal.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	index = 0;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	index = 0;
	while(index < other.index)
	{
		ideas[index] = other.ideas[index];
		index ++;
	}
}

Brain& Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return *this;
}

void Brain::addIdeas(std::string idea)
{
	std::cout << BOLDCYAN << index << RESET << std::endl;
	if (index >= 100)
	{
		std::cout << "the Brain is full" << std::endl;
		return;
	}
	std::cout << BOLDRED << " add : " << idea << " to the list" << RESET << std::endl;
	ideas[index] = idea;
	index ++;
}

void Brain::printIdeas() const
{
	for(int i = 0; i < index ; i ++)
		std::cout << ideas[i] <<std::endl;
}