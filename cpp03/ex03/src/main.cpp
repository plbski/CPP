#include"../include/ScavTrap.hpp"
#include"../include/FragTrap.hpp"

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
	FragTrap killer("killer");
	killer.HighFiveGuys();
	return(0);
}