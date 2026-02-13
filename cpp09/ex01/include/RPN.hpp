#pragma once

#include <iostream>
#include <stack>


class RPN {
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN& operator=(const RPN &other);
	void	calculation(std::string input);
private:
	std::stack<int> calcul;
};

