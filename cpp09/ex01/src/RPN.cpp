#include "../include/RPN.hpp"

RPN::RPN() {
	std::cout << "RPN default constructor called" << std::endl;
}

RPN::~RPN() {
	std::cout << "RPN destructor called" << std::endl;
}

RPN::RPN(const RPN &other) {
	std::cout << "RPN copy constructor called" << std::endl;
	*this = other;
}

RPN& RPN::operator=(const RPN &other) {
	std::cout << "RPN copy assignment operator called" << std::endl;
	if (this != &other) {
		calcul = other.calcul;
	}
	return *this;
}

bool is_operation(int c, std::stack<int> &calcul)
{
	int a;
	int b;
	if (calcul.size() < 2)
		return false;
	a = calcul.top();
	calcul.pop();
	b = calcul.top();
	calcul.pop();
	if (c == '-')
		calcul.push(b - a);
	else if (c == '+')
		calcul.push(b + a);
	else if (c == '*')
		calcul.push(b * a);
	else if (c == '/')
		calcul.push(b / a);
	else{
		calcul.push(b);
		calcul.push(a);
		return(false);
	}
	return true;
}

void RPN::calculation(std::string input){
	for (size_t i = 0; i < input.size(); i++){
		if (isdigit(input[i]))
			calcul.push(input[i] - '0');
		else if (input[i] != ' ' && !is_operation(input[i], calcul)){
			std::cout << "Error " << std::endl;
			return;
		}
	}
	if (calcul.size() == 1)
		std::cout << calcul.top() << std::endl;
	else
		std::cout << "Error end" << std::endl;
	return;
}
