#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &cp);
    ~ScavTrap();
	ScavTrap& operator=(const ScavTrap &sc);
	void		attack(const std::string& target);
	void	guardGate();

protected:
	static const int base_HP = 100;
	static const int base_E = 50;
	static const int base_D = 20;

};

#endif // SCAVTRAP_HPP
