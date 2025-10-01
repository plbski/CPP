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
	std::cout << BOLDGREEN << "[ INFO ] \n" <<RESET << "mode info online ... \nall good for know !" << std::endl;
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
	int i = 0;
	while (i < 4)
	{
		if (tab[i] == level)
			break;
		i ++;
	}
	switch (i)
	{
		case 0:
			(this->*func[i])();
			//fallthrough
		case 1:
			(this->*func[1])();
			//fallthrough
		case 2:
			(this->*func[2])();
			//fallthrough
		case 3:
			(this->*func[3])();
			return;
			//fallthrough
		default:
			break;
	}
	std::cout << "wrong level" << std::endl;
};