#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		void makeSound() const;
		void idea(std::string id);
		void printBrain();
	
	private:
		Brain* me;
};

#endif // DOG_HPP
