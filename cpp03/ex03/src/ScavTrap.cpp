#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string n) : ClapTrap(n, 100, 50, 20){
    std::cout << BOLDMAGENTA << "profession:   "<< RESET << "GUARDIAN"<< std::endl;
	std::cout << BOLDBLUE
              << "=====================================\n"
              << RESET;
}

ScavTrap::ScavTrap(const ScavTrap &cp): ClapTrap(cp.getName(), cp.getH_point(), cp.getE_point(), cp.getDamage())
{
	std::cout << BOLDMAGENTA << "profession:   "<< RESET << "COPY GUARDIAN"<< std::endl;
	std::cout << BOLDBLUE
              << "=====================================\n"
              << RESET;
}

ScavTrap::~ScavTrap() {
    std::cout << "class ScavTrap " << name << BOLDRED << " GET KILLED" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &st)
{
	(void)st;
	return(*this);
}

void ScavTrap::attack(const std::string& target)
{
	E_point --;
	std::cout << BOLDCYAN
	<< "\n	    >>> " << this->name << " <<<\n"
	<< "💣 bomb " << target  << " and inflict damage "
	<< damage << " 💣\n"
	<< RESET << std::endl;
	std::cout << E_point << " energie remain" << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << BOLDGREEN 
          << "\n	 ===== " << name << " =====\n"
          << "   >>> 🛡️  Guard Gate ACTIVATED 🛡️  <<<\n"
          << RESET << std::endl;
}