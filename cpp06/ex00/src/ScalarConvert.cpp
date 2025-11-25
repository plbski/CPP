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

bool ConvertibleToDouble(std::string string)
{
	try
	{
		std::stod(string);
	}
	catch(const std::out_of_range&)
	{
		std::cout << BOLDRED << "double : is out of range\n" << RESET << std::endl;
		return (false);
	}
	catch(const std::invalid_argument&)
	{
		std::cout << BOLDRED << "float : invalid\ndouble : argument not valid\n" << RESET << std::endl;
		return(false);
	}
	return(true);
}

bool ConvertibleToFloat(std::string string)
{
	try
	{
		std::stof(string);
	}
	catch(const std::out_of_range&)
	{
		std::cout << BOLDRED << "float : is out of range" << RESET << std::endl;
		return (false);
	}
	catch(const std::invalid_argument&)
	{
		std::cout << BOLDRED << "float : argument not valid" << RESET << std::endl;
		return(false);
	}
	return(true);
}

bool ConvertibleToInt(std::string string)
{
	try
	{
		std::stoi(string);
	}
	catch(const std::out_of_range&)
	{
		std::cout << BOLDRED << "char : not printable\nint : is out of range" << RESET << std::endl;
		return (false);
	}
	catch(const std::invalid_argument&)
	{
		std::cout << BOLDRED << "char : invalid \nint : invalid" << RESET << std::endl;
		return(false);
	}
	return(true);
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
	int i;
	char a;
	if (!CorrectInput(string))
	{
		std::cout << BOLDRED << "incorrect input" << RESET << std::endl;
		return;
	}
	if (ConvertibleToInt(string))
	{
		i = std::stoi(string);
		a = i;
		if (std::isprint(a))
			std::cout << "char : " << a;
		else
			std::cout << "char : not printable";
		std::cout << "\nint : " << i;

	}
	std::cout << std::showpoint;
	if (ConvertibleToFloat(string))
		std::cout  << "\nfloat : " << std::stof(string) <<"f\ndouble : " << std::stod(string)<< std::endl;
	else if (ConvertibleToDouble(string))
		std::cout << "\ndouble : " << std::stod(string)<< std::endl;
}
