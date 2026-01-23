#include<iostream>
#include <fstream>
#include<string>
#include "../include/ScalarConvert.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return(0);
	ScalarConvert::convert(av[1]);
	return(0);
}