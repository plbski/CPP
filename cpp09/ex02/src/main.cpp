#include "../include/PmergeMe.hpp"

int main(){
	std::vector<std::pair<int, int > > paires;
	paires.push_back(std::make_pair(99, 3));
	paires.push_back(std::make_pair(67, 5));
	paires.push_back(std::make_pair(23, 1));
	paires.push_back(std::make_pair(22, 15)); // Paire A
	paires.push_back(std::make_pair(7, 45));  // Paire C
	paires.push_back(std::make_pair(42, 10)); // Paire D
	paires.push_back(std::make_pair(8, 56));  // Paire E
	paires.push_back(std::make_pair(89, 12)); // Paire G
	test(paires);
}
