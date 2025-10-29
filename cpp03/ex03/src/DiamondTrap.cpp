#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string n): ClapTrap(n + "_clap_name"),FragTrap(n), ScavTrap(n)
{
	this->name = n;
	ClapTrap::name = n + "_clap_name";
	H_point = FragTrap::base_HP;
	E_point = ScavTrap::base_E;
	damage = FragTrap::base_D;
	std::cout << "XD diamond is born" << std::endl;
	printCharacterCard();
}
DiamondTrap::DiamondTrap(const DiamondTrap &cp): ClapTrap(cp.name + "_clap_name"), FragTrap(cp.name), ScavTrap(cp.name)
{
	H_point = cp.H_point;
	E_point = cp.E_point;
	damage = cp.damage;
	printCharacterCard();
	std::cout << "XD diamond copy is born" << std::endl;
}
DiamondTrap::~DiamondTrap() 
{
	std::cout << BOLDBLACK << "THE CREATURE IS LEAVING\n" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &dt)
{
	(void) dt;
	return(*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << BOLDBLACK << name << " is Diamond name\n" << RESET 
			<< BOLDWHITE << ClapTrap::name << " is ClapTrap name\n" << RESET << std::endl;
}