#include"../include/ScavTrap.hpp"

int main()
{
	ClapTrap jean("jean");
	jean.attack("random guys");
	jean.takeDamage(20);
	jean.beRepaired(20);
	jean.beRepaired(14);
	ScavTrap serena("serena");
	serena.attack("random guys");
	serena.beRepaired(20);
	serena.takeDamage(20);
	serena.beRepaired(14);
	return(0);
}