#include "Zombie.hpp"

int main()
{
	std::string name;
	std::cout << "enter a name: ";
	std::cin >> name;
	std::cout << std::endl;
	randomChump(name);
	std::cout << "enter in the main function" <<std::endl;
	std::cout << "enter a name: ";
	std::cin >> name;
	std::cout << std::endl;
	Zombie *greg = newZombie(name);
	std::cout << "enter in the main function" <<std::endl;
	greg->announce();
	std::cout << "we need to dealloc him manually" << std::endl;
	delete greg;
	return (0);
}
