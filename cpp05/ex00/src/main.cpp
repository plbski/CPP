#include "../include/Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat bob("bob", 166);
		Bureaucrat charle("Charle", 1);
	}

	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}