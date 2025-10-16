#include"../include/ScavTrap.hpp"

int main()
{
	ClapTrap jean("jean");
	jean.attack("random guys");
	ScavTrap serena("serena");
	serena.attack("random guys");
	serena.beRepaired(20);
	serena.takeDamage(20);
	serena.beRepaired(14);
	serena.guardGate();
	return(0);
}