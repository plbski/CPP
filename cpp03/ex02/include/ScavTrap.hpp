#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name);
	ScavTrap(const ClapTrap &cp);
    ~ScavTrap();
	void		attack(const std::string& target);
	void	guardGate();

private:
    // fields
};

#endif // SCAVTRAP_HPP
