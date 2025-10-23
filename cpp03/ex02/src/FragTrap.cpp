#include "../include/FragTrap.hpp"

FragTrap::FragTrap(std::string n) : ClapTrap(n, 100, 100, 30){
    std::cout << BOLDMAGENTA << "profession:   "<< RESET << "MONK"<< std::endl;
	std::cout << BOLDBLUE
              << "=====================================\n"
              << RESET;
}

FragTrap::FragTrap(const FragTrap &cp): ClapTrap(cp.getName(), cp.getH_point(), cp.getE_point(), cp.getDamage())
{
	std::cout << BOLDMAGENTA << "profession:   "<< RESET << "COPY MONK"<< std::endl;
	std::cout << BOLDBLUE
              << "=====================================\n"
              << RESET;
}

FragTrap::~FragTrap() {
    std::cout << "class FragTrap " << name << BOLDRED << "RUN AWAY" << RESET << std::endl;
}

void FragTrap::HighFiveGuys()
{
		std::cout << BOLDWHITE
          << "\n	 ===== " << name << " =====\n"
          << "   >>> 🤜 ASK FOR HIGHFIVE 🤛 <<<\n"
          << RESET << std::endl;
}
