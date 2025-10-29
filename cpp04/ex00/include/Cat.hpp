#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);
		void makeSound() const;
	private:
		// fields
};

#endif // CAT_HPP
