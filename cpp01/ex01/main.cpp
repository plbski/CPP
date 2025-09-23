#include "Zombie.hpp"

int main()
{
	int N;

	std::cout<< "how many zombie :";
	std::cin >> N;
	std::cout << std::endl;
	Zombie *bob = zombieHorde( N,"bob");
	for (int i = 0; i < N ; i ++)
		bob[i].announce();
	delete[] bob;
	return(0);
}