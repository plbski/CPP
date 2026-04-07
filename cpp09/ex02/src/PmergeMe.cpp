#include <vector>
#include <algorithm>
#include <iostream>
#include "../include/PmergeMe.hpp"

//vector function ---------------------------------------------------------------------------
static std::string indent(int depth)
{
	return std::string(depth * 2, ' ');
}

// std::string vecToStr(const std::vector<Node> &v)
// {
// 	std::string s = "[ ";
// 	for (size_t i = 0; i < v.size(); i++)
// 	{
// 		s += std::to_string(v[i].value);
// 		if (i + 1 < v.size()) s += ", ";
// 	}
// 	return s + " ]";
// }

// static void printBattle(const std::vector<Node> &paire, int depth)
// {
// 	std::string ind = indent(depth);
// 	std::cout << ind << "┌─ BATTLES\n";
// 	for (size_t i = 0; i + 1 < paire.size(); i += 2)
// 	{
// 		int a = paire[i].value;
// 		int b = paire[i + 1].value;
// 		int winner = (a > b) ? a : b;
// 		int loser  = (a > b) ? b : a;
// 		std::cout << ind << "│  " << a << " vs " << b
// 				<< "  →  winner: " << winner
// 				<< "  loser: " << loser << "\n";
// 	}
// }

// static void printMainchain(const std::vector<Node> &chain, int depth)
// {
// 	std::cout << indent(depth) << "├─ MAINCHAIN (sorted winners): "
// 			<< vecToStr(chain) << "\n";
// }

// static void printPchain(const std::vector<Node> &P, int depth)
// {
// 	std::cout << indent(depth) << "├─ P (losers linked to winners): "
// 			<< vecToStr(P) << "\n";
// }

// static void printResultBeforeJacob(const std::vector<Node> &result, int depth)
// {
// 	std::cout << indent(depth) << "├─ result before Jacob (P[0] prepended): "
// 			<< vecToStr(result) << "\n";
// }

// static void printInsertion(const Node &node, size_t pos,
// 						const std::vector<Node> &result, int depth)
// {
// 	std::cout << indent(depth) << "│  insert " << node.value
// 			<< " at position " << pos
// 			<< "  →  " << vecToStr(result) << "\n";
// }

// static void printJacobHeader(int depth)
// {
// 	std::cout << indent(depth) << "├─ JACOB INSERTIONS\n";
// }

// static void printStraggler(const Node &s, int depth)
// {
// 	std::cout << indent(depth) << "└─ straggler " << s.value << " inserted\n";
// }

void print_dequeNode(std::deque<Node> paire)
{
	for (size_t i = 0; i < paire.size() - 1; i++)
		std::cout << paire[i].value << " ";
	std::cout << paire[paire.size() - 1].value << std::endl;
}

void print_vectorNode(std::vector<Node> paire)
{
	for (size_t i = 0; i < paire.size() - 1; i++)
		std::cout << paire[i].value << " ";
	std::cout << paire[paire.size() - 1].value << std::endl;
}

void insertJacob(std::vector<Node> &result, std::vector<Node> &P, int depth)
{
	(void) depth;
	size_t jacobArray[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365};
	size_t last_inserted_idx = 1;

	for (size_t k = 1; k < 11; ++k)
	{
		size_t target_idx = jacobArray[k];
		if (target_idx > P.size())
			target_idx = P.size();

		// std::cout << indent(depth) << "│  Jacob group k=" << k
		// 		<< "  range [" << last_inserted_idx + 1
		// 		<< ".." << target_idx << "] (right→left)\n";

		for (size_t j = target_idx; j > last_inserted_idx; --j)
		{
			Node to_insert = P[j - 1];

			std::vector<Node>::iterator it = std::lower_bound(
				result.begin(), result.end(), to_insert, NodeCompare());

			result.insert(it, to_insert);

			// size_t pos = static_cast<size_t>(it - result.begin());
			// printInsertion(to_insert, pos, result, depth);
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

std::vector<Node> fj(std::vector<Node> paire, int depth)
{
	std::vector<Node> G;
	std::vector<Node> P;
	std::vector<Node> result;
	std::vector<Node> mainchain;
	Node straggler;
	std::vector<Node>::iterator it;

	std::string ind = indent(depth);

	// std::cout << "\n" << ind << "══ fj depth=" << depth
	// 		<< "  input: " << vecToStr(paire) << "\n";

	if (paire.size() <= 1)
	{
		// std::cout << ind << "  base case → return " << vecToStr(paire) << "\n";
		return paire;
	}

	bool has_straggler = false;
	if (paire.size() % 2 != 0)
	{
		straggler = paire.back();
		paire.pop_back();
		has_straggler = true;
		// std::cout << ind << "  odd size → straggler saved: " << straggler.value
		// 		<< "  remaining: " << vecToStr(paire) << "\n";
	}

	// printBattle(paire, depth);
	battle(G, paire);
	// std::cout << ind << "│  winners G: " << vecToStr(G) << "\n";

	mainchain = fj(G, depth + 1);

	// printMainchain(mainchain, depth);

	for (size_t i = 0; i < mainchain.size(); i++)
	{
		P.push_back(mainchain[i].loser.back());
		mainchain[i].loser.pop_back();
	}
	// printPchain(P, depth);

	result = mainchain;
	result.insert(result.begin(), P[0]);
	// printResultBeforeJacob(result, depth);

	insertJacob(result, P, depth);

	if (has_straggler)
	{
		it = std::lower_bound(
			result.begin(), result.end(), straggler, NodeCompare());
		result.insert(it, straggler);
		// printStraggler(straggler, depth);
	}

	// std::cout << ind << "  result: " << vecToStr(result) << "\n";
	return result;
}

//deque function ---------------------------------------------------------------------------


void insertJacobDeque(std::deque<Node> &result, std::deque<Node> &P, int depth)
{
	(void) depth;
	size_t jacobArray[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365};
	size_t last_inserted_idx = 1;

	for (size_t k = 1; k < 11; ++k)
	{
		size_t target_idx = jacobArray[k];
		if (target_idx > P.size())
			target_idx = P.size();

		for (size_t j = target_idx; j > last_inserted_idx; --j)
		{
			Node to_insert = P[j - 1];

			std::deque<Node>::iterator it = std::lower_bound(
				result.begin(), result.end(), to_insert, NodeCompare());

			result.insert(it, to_insert);
		}

		last_inserted_idx = target_idx;
		if (last_inserted_idx >= P.size())
			break;
	}
}

void battleDeque(std::deque<Node> &G, std::deque<Node> paire)
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

std::deque<Node> fj_deque(std::deque<Node> paire, int depth)
{
	std::deque<Node> G;
	std::deque<Node> P;
	std::deque<Node> result;
	std::deque<Node> mainchain;
	Node straggler;
	std::deque<Node>::iterator it;

	std::string ind = indent(depth);

	if (paire.size() <= 1)
	{
		return paire;
	}

	bool has_straggler = false;
	if (paire.size() % 2 != 0)
	{
		straggler = paire.back();
		paire.pop_back();
		has_straggler = true;
	}

	battleDeque(G, paire);

	mainchain = fj_deque(G, depth + 1);


	for (size_t i = 0; i < mainchain.size(); i++)
	{
		P.push_back(mainchain[i].loser.back());
		mainchain[i].loser.pop_back();
	}

	result = mainchain;
	result.insert(result.begin(), P[0]);

	insertJacobDeque(result, P, depth);

	if (has_straggler)
	{
		it = std::lower_bound(
			result.begin(), result.end(), straggler, NodeCompare());
		result.insert(it, straggler);
	}
	return result;
}
