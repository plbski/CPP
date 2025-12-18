#include "../include/ScalarConvert.hpp"

ScalarConvert::ScalarConvert() {
	// std::cout << "ScalarConvert default constructor called" << std::endl;
}

ScalarConvert::~ScalarConvert() {
	// std::cout << "ScalarConvert destructor called" << std::endl;
}

ScalarConvert::ScalarConvert(const ScalarConvert &other) {
	// std::cout << "ScalarConvert copy constructor called" << std::endl;
	*this = other;
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert &other) {
	std::cout << "ScalarConvert copy assignment operator called" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return *this;
}

bool isDouble(std::string string)
{
	char *end = NULL;
	double val = strtod(string.c_str(), &end);
	(void)val;

	if (*end != '\0')
		return(false);
	return(true);
}

bool isFloat(std::string string)
{
	float maxFloat = std::numeric_limits<float>::max();
	float minFloat = std::numeric_limits<float>::max() * -1;
	char *end = NULL;
	double val = strtof(string.c_str(), &end);
	const char* test = std::strrchr(string.c_str(), '.');

	std::cout << *end <<std::endl;
	if (*end != 'f' || std::strlen(end) > 1 || val < minFloat || val > maxFloat || test == NULL)
		return(false);
	return(true);
}

bool isInt(std::string string)
{
	int maxInt = std::numeric_limits<int>::max();
	int minInt = std::numeric_limits<int>::max() * -1;
	char *end = NULL;
	long val = strtol(string.c_str(), &end, 10);

	if (val < minInt || val > maxInt || *end != '\0')
		return(false);
	return(true);
}

bool isChar(std::string string)
{
	const char *str = string.c_str();
	int val= str[0];
	if (string.size() == 1 && std::isprint(val))
		return(true);
	return(false);
}

void ScalarConvert::convert(std::string string)
{
	if (isInt(string))
	{
		std::cout << string << " is int" << std::endl;
		int i = strtol(string.c_str(), NULL, 10);
		float f = static_cast<float> (i);
		double d= static_cast<double> (i);
		std::cout << i << '\n' << f << ".0f\n" << d << ".0" << std::endl;
	}
		
	else if (isFloat(string))
	{
		std::cout << string << " is float" << std::endl;
		char *end;
		double f = strtod(string.c_str(), &end);
		std::cout<< *end << std::endl;
		int i = static_cast<int> (f);
		double d= static_cast<double> (f);
		if (std::floor(f) == f)
			std::cout << i << '\n' << f << ".0f\n" << d << ".0" << std::endl;
		else
			std::cout << i << '\n' << f << ".f\n" << d <<std::endl;
	}
		
	else if (isDouble(string))
		std::cout << string << " is double"<<std::endl;
	else if (isChar(string))
		std::cout << string << " is char" << std::endl;
	else
		std::cout << "invalid input" << std::endl;
	return;
}