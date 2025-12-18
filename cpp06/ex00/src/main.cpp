#include<iostream>
#include <fstream>
#include<string>
#include "../include/ScalarConvert.hpp"

int main(int ac, char **av)
{
	ScalarConvert test;

	if (ac != 2)
		return(0);
	test.convert(av[1]);
	return(0);
}