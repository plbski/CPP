#include"Harl.hpp"

int main()
{
	Harl filou = Harl();
	std::string level;
	while(true)
	{
		std::cout << "choose ur Harl level [DEBUG] [INFO] [WARNING] [ERROR]: " << std::endl;
		std::cin >> level;
		if (std::cin.eof())
			return(0);
		std::cout << std::endl;
		filou.complain(level);
	}
	
	return(0);
}