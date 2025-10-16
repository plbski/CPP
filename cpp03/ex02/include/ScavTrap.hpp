#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name);
    ~ScavTrap();
	void	guardGate();

private:
    // fields
};

#endif // SCAVTRAP_HPP
