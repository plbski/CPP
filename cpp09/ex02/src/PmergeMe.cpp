#include <vector>
#include <algorithm>
#include <iostream>
#include "../include/PmergeMe.hpp"

void print_vectorNode(std::vector<Node> paire)
{
	for (size_t i = 0; i < paire.size() - 1; i ++)
		std::cout << paire[i].value << " < ";
	std::cout << paire[paire.size() - 1].value <<std::endl;
}

void insertJacob(std::vector<Node> &result, std::vector<Node> &P)
{
		size_t jacobArray[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365};
	size_t last_inserted_idx = 1; 

	for (size_t k = 1; k < 11; ++k) {
		size_t target_idx = jacobArray[k];
		if (target_idx > P.size()) 
			target_idx = P.size();

		// On insère de la droite vers la gauche entre last et target
		for (size_t j = target_idx; j > last_inserted_idx; --j) {
			Node to_insert = P[j - 1];
			
			// Recherche binaire
			std::vector<Node>::iterator it = std::lower_bound(
				result.begin(), 
				result.end(), 
				to_insert, 
				NodeCompare()
			);
			result.insert(it, to_insert);
		}
		last_inserted_idx = target_idx;
		if (last_inserted_idx >= P.size()) 
			break;
	}
}

void battle(std::vector<Node> &G, std::vector<Node> paire)
{
	for (size_t i = 0; i + 1 < paire.size(); i += 2)
	{
		if (paire[i].value > paire[i + 1].value)
		{
			paire[i].loser.push_back(paire[i + 1]);
			G.push_back(paire[i]);
		}
		else
		{
			paire[i + 1].loser.push_back(paire[i]);
			G.push_back(paire[i + 1]);
		}
	}
}

std::vector<Node> fj(std::vector<Node> paire)
{
	// CAS DE BASE
	std::vector<Node> G;
	std::vector<Node> P;
	std::vector<Node> result;
	std::vector<Node> mainchain;
	Node straggler;
	std::vector<Node>::iterator it;


	if (paire.size() <= 1)
		return paire;
	bool has_straggler = false; 
	
	if (paire.size() % 2 != 0) {
		straggler = paire.back();
		paire.pop_back();
		has_straggler = true;
	}
	battle(G, paire);
	mainchain = fj(G);
	for (size_t i = 0; i < mainchain.size(); i++) {
		P.push_back(mainchain[i].loser.back());
		mainchain[i].loser.pop_back();
	}
	result = mainchain;
	result.insert(result.begin(), P[0]);
	insertJacob(result, P);
	if (has_straggler) {
		it = std::lower_bound(
			result.begin(), 
			result.end(), 
			straggler, 
			NodeCompare()
		);
		result.insert(it, straggler);
	}
	return result;
}
