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
	float minFloat = std::numeric_limits<float>::min();
	char *end = NULL;
	double val = strtod(string.c_str(), &end);

	std::
	std::cout << val << std::endl;
	if (*end != 'f' || val < minFloat || val > maxFloat)
		return(false);
	return(true);
}

bool isInt(std::string string)
{
	int maxInt = std::numeric_limits<int>::max();
	int minInt = std::numeric_limits<int>::min();
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
bool CorrectInput(std::string string)
{
	size_t i = 0;
	int point = 0;

	if (string == "-inf" || string == "+inf" || string == "-inff" || string == "+inff")
		return(true);
	if (string[i] == '-')
		i ++;
	while (i < string.size())
	{
		if (string[i] == '.')
			point ++;
		if (point > 1)
			break;
		else if(!std::isdigit(string[i]) && string[i] != '.')
			break;
		i ++;
	}
	if (i ==  string.size() || (string[i] == 'f' && i + 1==  string.size()))
		return(true);
	return(false);
}

void ScalarConvert::convert(std::string string)
{
	if (isInt(string))
		std::cout << string << " is int" << std::endl;
	else if (isFloat(string))
		std::cout << string << " is float" << std::endl;
	else if (isDouble(string))
		std::cout << string << " is double" << std::endl;
	else if (isChar(string))
		std::cout << string << " is char" << std::endl;

	return;
}