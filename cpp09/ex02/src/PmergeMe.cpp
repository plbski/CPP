#include "../include/PmergeMe.hpp"

void test(std::vector<std::pair<int, int> > paire)
{
	std::vector<std::pair<int, int> >::iterator it;
	std::vector<int> G;
	std::vector<int> P;
	for (it = paire.begin(); it != paire.end(); ++it)
	{
		if (it->first < it->second){
			std::swap(it->first, it->second);
		}
		if(it->second)
		{
			G.push_back(it->first);
			P.push_back(it->second);
		}
	}
	// tri des gagnant( a faire avec fordjohnson losqu'il marchera)

}
