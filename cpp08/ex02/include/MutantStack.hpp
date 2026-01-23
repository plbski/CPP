#pragma once


#include<string>
#include<iostream>
#include<vector>
#include <stack>
#include<deque>

class MutantStack
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack& operator=(const MutantStack& other);
	
	private:
		std::stack<int> test;
};

