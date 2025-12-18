#include "../include/ScalarConvert.hpp"


void printFloat(std::string string)
{
	std::cout << string << " is float" << std::endl;
	char c;
	float f = strtof(string.c_str(), NULL);
	if (string == "nanf" || string == "-inff" || string == "inff")
	{
		std::cout << "char : impossible\nint : impossible\nfloat : " << f << "f\ndouble : " << f << std::endl;
		return;
	}
	std::cout << std::fixed << std::setprecision(std::strlen(std::strchr(string.c_str(), '.'))- 2);
	int i = static_cast<int> (f);
	double d= static_cast<double> (f);
	if(std::isprint(i))
	{
		c = i;
		std::cout << "char: "<< c << "\nint : " << i << "\nfloat : " << f << ".0f\ndouble" << d << ".0" << std::endl;
	}
	else
	 std::cout << "char : Non displayable\nint : " << i << "\nfloat : " << f << ".0f\ndouble" << d << ".0" << std::endl;
}
