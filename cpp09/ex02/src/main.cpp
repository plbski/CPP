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
	std::vector<Node> test;
	for (int i = 1; i < ac; i ++){
		Node a;
		a.value = std::strtol(av[i], NULL, 10);
		test.push_back(a);
	}
	fj(test);
}
