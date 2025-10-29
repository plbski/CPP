#include "../include/Brain.hpp"

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
	if (index > 99)
	{
		std::cout << "the Brain is full" << std::endl;
		return;
	}
	ideas[index] = idea;
	index ++;
}

void Brain::printIdeas()
{
	for(int i = 0; i < index ; i ++)
		std::cout << ideas[i] << std::endl;
}