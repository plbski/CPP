#include "../include/PmergeMe.hpp"

int main(int ac, char **av){
	// std::vector<std::pair<int, int > > paires;
	// paires.push_back(std::make_pair(99, 3));
	// paires.push_back(std::make_pair(67, 5));
	// paires.push_back(std::make_pair(23, 1));
	// paires.push_back(std::make_pair(22, 15)); // Paire A
	// paires.push_back(std::make_pair(7, 45));  // Paire C
	// paires.push_back(std::make_pair(42, 10)); // Paire D
	// paires.push_back(std::make_pair(8, 56));  // Paire E
	// paires.push_back(std::make_pair(89, 12)); // Paire G
	// test(paires);
	std::srand(time(0));
	std::vector<Node> test;
	if (ac <= 1)
	{
		for (int i = 0; i < 3000 ; i ++)
		{
			Node b;
			b.value = std::rand() % 100000;
			test.push_back(b);
		}
	}
	else
	{
		for (int i = 1; i < ac; i ++){
			Node a;
			a.value = std::strtol(av[i], NULL, 10);
			test.push_back(a);
		}
	}
	print_vectorNode(fj(test));
}

