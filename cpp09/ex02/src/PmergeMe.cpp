#include "../include/PmergeMe.hpp"

size_t john[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731};

void printVectorPaire(std::vector<std::pair<int, int> > &v) {
	std::vector<std::pair<int, int> >::iterator it;
    for (it = v.begin(); it < v.end(); ++it) {
        std::cout << "{" << it->first << " ";
		std::cout << it->second << "}, ";
    }
    std::cout << std::endl;
}

void printVector(std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void test(std::vector<std::pair<int, int> > paire)
{
	std::vector<std::pair<int, int> >::iterator it;
	std::vector<int>	G;
	std::vector<int>	P;
	size_t				save;
	(void)save;
	it = paire.end();
	// if (!it->second){
	// 	save = it->first;
	// 	paire.pop_back();
	// }
	for (it = paire.begin(); it != paire.end(); ++it)
	{
		if (it->first < it->second){
			std::swap(it->first, it->second);
		}
	}
	// tri des gagnant( a faire avec fordjohnson losqu'il marchera)
	std::sort(paire.begin(), paire.end());
	// premier gratuit
	for (it = paire.begin(); it < paire.end(); it ++)
	{
		G.push_back(it->first);
		P.push_back(it->second);
	}
	// premier gratuit
	G.insert(G.begin(), P[0]);
	std::vector<int>::iterator te;
	size_t current;
	size_t pos = 1;
	//bon jusque la 
	for (size_t i = 1; john[i] || john[i] >= P.size(); i ++){
		current = john[i];
		if (current > P.size() )
			current = P.size();
		for (size_t j = current - 1; j > john[i - 1] - 1; j --){
			te = std::lower_bound(G.begin(), G.begin() + j + pos, P[j]);
			G.insert(te, P[j]);
			pos ++;
		}
	}
	std::cout << std::endl;
	printVector(G);
}
// 1, 3, 5, 7, 8, 10, 12, 15, 22, 23, 34, 42, 45, 56, 67, 89, 99
