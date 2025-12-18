#include "../include/ScalarConvert.hpp"


void cInt(std::string string,int *i,float *f,double *d)
{
	std::cout << string << " is int" << std::endl;
	*i = strtol(string.c_str(), NULL, 10);
	*f = static_cast<float> (*i);
	*d= static_cast<double> (*i);
}

void cFloat(std::string string,int *i,float *f,double *d)
{
	int maxInt = std::numeric_limits<int>::max();
	int minInt = std::numeric_limits<int>::max() * -1;

	std::cout << string << " is float" << std::endl;
	*f = strtof(string.c_str(), NULL);
	if (string != "nanf" && string != "-inff" && string != "inff")
	{
		std::cout << std::fixed << std::setprecision(std::strlen(std::strchr(string.c_str(), '.'))- 2);
		if (*d < maxInt && *d > minInt)
			*i = static_cast<int> (*d);
		else
			*i = maxInt;
		*d= static_cast<double> (*f);
	}
}

void cDouble(std::string string,int *i,float *f,double *d)
{
	int maxInt = std::numeric_limits<int>::max();
	int minInt = std::numeric_limits<int>::max() * -1;
	int maxFloat = std::numeric_limits<float>::max();
	int minFloat = std::numeric_limits<float>::max() * -1;

	std::cout << string << " is double"<<std::endl;
	*d = strtod(string.c_str(), NULL);
	if (string != "nan" && string != "-inf" && string != "inf")
	{
		std::cout << std::fixed << std::setprecision(std::strlen(std::strchr(string.c_str(), '.')) - 1);
		if (*d < maxInt && *d > minInt)
			*i = static_cast<int> (*d);
		else
			*i = maxInt;
		if (*d < maxFloat && *d > minFloat)
			*f= static_cast<float> (*d);
		else 
			*f = maxFloat;
	}
}

void cChar(std::string string, int *i, float *f, double *d, char *c)
{
	*c = string[0];
	*i = *c;
	*f = static_cast<float> (*i);
	*d= static_cast<double> (*i);
}
