#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string n) : ClapTrap(n, 100, 50, 20){
    std::cout << "class ScavTrap " << n << " create" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "class ScavTrap " << this->getName() << " destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << BOLDGREEN 
          << "\n	 ===== " << this->getName() << " =====\n"
          << "   >>> 🛡️ Guard Gate ACTIVATED 🛡️ <<<\n"
          << RESET << std::endl;
}