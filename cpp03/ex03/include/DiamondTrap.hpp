#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
public:
    DiamondTrap(std::string n);
	DiamondTrap(const DiamondTrap &cp);
    ~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap &dt);
	void whoAmI();

	using ScavTrap::attack;

private:
    std::string name;
};

#endif // DIAMONDTRAP_HPP
