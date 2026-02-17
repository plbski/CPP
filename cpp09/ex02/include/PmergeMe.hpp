#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

struct Node{
	int value;
	std::vector<Node> loser;
};

void test(std::vector<std::pair<int, int> > paire);
void fj(std::vector<Node> paire);

