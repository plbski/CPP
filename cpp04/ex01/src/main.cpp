#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main()
{
	Animal* array[4];
	for (int i = 0; i < 2 ; i++)
		array[i] = new Cat();
	for (int i = 2; i < 4; i++)
		array[i] = new Dog();
	for(int i = 0; i < 5; i++)
		delete array[i];
	Animal* k = new Dog();
	k->idea("good");
	return(0);
}