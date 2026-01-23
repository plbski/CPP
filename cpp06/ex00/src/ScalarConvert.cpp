#include "../include/ScalarConvert.hpp"

ScalarConvert::ScalarConvert() {
	// std::cout << "ScalarConvert default constructor called" << std::endl;
}

bool isDouble(std::string string)
{
	char *end = NULL;
	double val = strtod(string.c_str(), &end);
	(void)val;

	const char* test = std::strchr(string.c_str(), '.');
	if (string == "nan" || string == "-inf" || string == "inf")
	{
		std::cout << "char : impossible\nint : impossible\nfloat : " << val << "f\ndouble : " << val << std::endl;
		return(false);
	}
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
	{
		std::cout << "char : impossible\nint : impossible\nfloat : " << val << "f\ndouble : " << val << std::endl;
		return(false);
	}
	if (*end != 'f' || std::strlen(end) > 1 || val < minFloat || val > maxFloat || !test || std::strlen(test) < 3)
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
	int		maxInt = std::numeric_limits<int>::max();
	int		minInt = std::numeric_limits<int>::max() * -1;
	float	maxFloat = std::numeric_limits<float>::max();
	float	minFloat = std::numeric_limits<float>::max() * -1;
	std::cout << std::fixed << std::setprecision(1);

	if (isInt(string))
		cInt(string, &i, &f,&d);
	else if (isFloat(string))
		cFloat(string, &i, &f,&d);
	else if (isDouble(string))
		cDouble(string, &i, &f,&d);
	else if (isChar(string))
		cChar(string, &i, &f,&d, &c);
	else
		return;
	if (d < maxInt && d >  minInt)
	{
		c = i;
		if (std::isprint(i))
			std::cout << "char: "<< c << "\nint : " << i <<std::endl;
		else
			std::cout << "char: non displable" << "\nint : " << i <<std::endl;
	}
	else
		std::cout << "char : impossible\nint : impossible" << std::endl;
	if (d < maxFloat && d >  minFloat)
		std::cout << "float : " << f << "f\ndouble : " << d << std::endl;
	else
		std::cout << "float : impossible\ndouble : " << d << std::endl;
	return;
}

