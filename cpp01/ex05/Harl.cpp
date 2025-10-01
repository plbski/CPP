#include "Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

// void help(){};


void Harl::debug()
{
	std::cout << "debug mode" << std::endl;
}
void Harl::info()
{
	std::cout << "info mode" << std::endl;
}

void Harl::warning()
{
	std::cout << "warning mode" << std::endl;
}

void Harl::error()
{
	std::cout<< "error mode "<< std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*func[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string tab[] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i ++)
	{
		if (tab[i] == level)
		{
			(this->*func[i])();
			return;
		}
			
	}
	std::cout << "wrong level" << std::endl;
};