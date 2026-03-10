#include "../include/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "you need to enter a RPN in second parameter" << std::endl;
		return(1);
	}
	RPN test;
	test.calculation(av[1]);
	return(0);
}
