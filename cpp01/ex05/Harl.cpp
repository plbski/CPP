#include "Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

// void help(){};


void Harl::debug()
{
	std::cout << BOLDWHITE << "[ DEBUG ] \n" << RESET << "mode debogage online ... \nlet me check where is ur mistake !" << std::endl;
}
void Harl::info()
{
	std::cout << BOLDGREEN << "[ INFO ] \n" <<RESET << "mode info online ... \nall good for now !" << std::endl;
}

void Harl::warning()
{
	std::cout << BOLDYELLOW << "[ WARNING ] \n" << RESET << "warning online ... \nhmmm that don't smell good u should stop know !" << std::endl;
}

void Harl::error()
{
	std::cout<< BOLDRED << "[ ERROR ] \n" << RESET << "mode error online ... \nare u crazy ur computer going to die stop that !!! \n\n\n"<< std::endl;
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