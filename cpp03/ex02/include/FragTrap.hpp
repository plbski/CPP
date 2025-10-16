#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string n);
		FlapTrap(const FlapTrap &cp);
		~FragTrap();

	private:
    // fields
};

#endif // FRAGTRAP_HPP
