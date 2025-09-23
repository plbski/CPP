#include "Zombie.hpp"

int main()
{
	std::string name;
	std::cout << "enter a name: ";
	std::cin >> name;
	std::cout << std::endl;
	randomChump(name);
	std::cout << "the zombie is dead in the fonction chump, he was on the stack" <<std::endl;
	std::cout << "enter a name: ";
	std::cin >> name;
	std::cout << std::endl;
	Zombie *greg = newZombie(name);
	std::cout << "we are in the main" << std::endl;
	greg->announce();
	std::cout << "we need to deallochim manually" << std::endl;
	delete greg;
	return (0);
}
