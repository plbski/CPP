#include"../include/ScavTrap.hpp"
#include"../include/FragTrap.hpp"
#include"../include/DiamondTrap.hpp"

int main()
{
	DiamondTrap dia("test");
	dia.attack("ANYONE");
	dia.whoAmI();
	DiamondTrap copy(dia);
	copy.guardGate();
	copy.takeDamage(20);
	dia.HighFiveGuys();
	return(0);
}