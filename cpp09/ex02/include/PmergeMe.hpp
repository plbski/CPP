#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

struct Node{
	int value;
	std::vector<Node> loser;
};

struct NodeCompare {
	bool operator()(const Node& a, const Node& b) const {
		return a.value < b.value;
	}
};

std::vector<Node> fj(std::vector<Node> paire);
void print_vectorNode(std::vector<Node> paire);

