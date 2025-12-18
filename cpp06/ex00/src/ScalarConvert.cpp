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

	const char* test = std::strchr(string.c_str(), '.');
	if (*end != '\0' || !test || std::strlen(test)< 2)
		return(false);
	return(true);
}

bool isFloat(std::string string)
{
	float maxFloat = std::numeric_limits<float>::max();
	float minFloat = std::numeric_limits<float>::max() * -1;
	char *end = NULL;
	double val = strtof(string.c_str(), &end);
	const char* test = std::strchr(string.c_str(), '.');

	if (string == "nanf" || string == "-inff" || string == "inff")
		return(true);
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
	int		i;
	float	f;
	double	d;
	char	c;
	int maxInt = std::numeric_limits<int>::max();
	int minInt = std::numeric_limits<int>::max() * -1;

	if (isInt(string))
	{
		std::cout << string << " is int" << std::endl;
		i = strtol(string.c_str(), NULL, 10);
		f = static_cast<float> (i);
		d= static_cast<double> (i);
	}
		
	else if (isFloat(string))
	{
		std::cout << string << " is float" << std::endl;
		f = strtof(string.c_str(), NULL);
		std::cout << std::fixed << std::setprecision(std::strlen(std::strchr(string.c_str(), '.'))- 2);
		i = static_cast<int> (f);
		d= static_cast<double> (f);
	}
		
	else if (isDouble(string))
	{
		std::cout << string << " is double"<<std::endl;
		d = strtod(string.c_str(), NULL);
		std::cout << std::fixed << std::setprecision(std::strlen(std::strchr(string.c_str(), '.')) - 1);

		if (d < maxInt && d > minInt)
			i = static_cast<int> (d);
		else
			i = maxInt;
		f= static_cast<float> (d);
	}

	// else if (isChar(string))
	// 	std::cout << string << " is char" << std::endl;
	// else
	// 	std::cout << "invalid input" << std::endl;

	if (string == "nan" || string == "-inf" || string == "inf")
		{
			std::cout << "char : impossible\nint : impossible\nfloat : " << d << "f\ndouble : " << d << std::endl;
			return;
		}
	else if (string == "nanf" || string == "-inff" || string == "inff")
	{
			std::cout << "char : impossible\nint : impossible\nfloat : " << f << "f\ndouble : " << f << std::endl;
			return;
	}
	else if (i < maxInt && i >  minInt)
		{
			c = i;
			if (std::isprint(i))
				std::cout << "char: "<< c << "\nint : " << i << "\nfloat : " << f << ".0f\ndouble" << d << ".0" << std::endl;
			else
				std::cout << "char: non displable" << "\nint : " << i << "\nfloat : " << f << ".0f\ndouble" << d << ".0" << std::endl;
		}
	else
		 std::cout << "char : impossible\nint : impossible" << "\nfloat : " << f << ".0f\ndouble" << d << ".0" << std::endl;
	return;
}
