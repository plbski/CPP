#pragma once


#include<string>
#include<iostream>
#include<vector>
#include <stack>
#include<deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack& operator=(const MutantStack& other);
	
	private:
};

