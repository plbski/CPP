#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"
#include "../include/WrongAnimal.hpp"

int main()
{
	const Animal* test = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	std::cout << i->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << test->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	test->makeSound();

	delete test;
	delete i;
	delete j;

	std::cout << BOLDRED << "TEST WRONG CLASS" << RESET << std::endl;
	const WrongAnimal* k = new WrongAnimal();
	const WrongAnimal* l = new WrongCat();
	l->makeSound();
	k->makeSound();
	delete(l);
	delete(k);
	return(0);
}