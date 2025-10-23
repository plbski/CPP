#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
public:
    DiamondTrap();
	DiamondTrap(const DiamondTrap &cp);
    ~DiamondTrap();
	void whoAmI();

private:
    std::string name;
};

#endif // DIAMONDTRAP_HPP
