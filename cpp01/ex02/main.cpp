#include <string>
#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;

	std::cout << "s	   :" << &s << "\n"
			<<"stringPTH : " << stringPTR << "\n"
			<<"stringREF : " << &stringREF << std::endl;

	std::cout << "s	  : " << s << "\n"
		<<"stringPTH : " << *stringPTR << "\n"
		<<"stringREF : " << stringREF << std::endl;

	stringREF = "test";
	*stringPTR = "test2";
	std::cout << "s	  : " << s << "\n"
		<<"stringPTH : " << *stringPTR << "\n"
		<<"stringREF : " << stringREF << std::endl;
}