#include "../include/easyfind.hpp"

int main()
{
	int a[3] ={1,2,3};
	std::vector<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	std::cout << finder(a, 1) << std::endl;
	std::cout << finder(b, 5) << std::endl;
	return(0);
}