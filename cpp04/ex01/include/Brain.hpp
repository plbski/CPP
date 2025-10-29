#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain& operator=(const Brain &other);
	void addIdeas(std::string idea);
	void printIdeas();

private:
	std::string ideas[100];
	int	index;
};

#endif // BRAIN_HPP
