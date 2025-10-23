#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap &cp);
    ~FragTrap();
	void		HighFiveGuys();

private:
    // fields
};

#endif // FRAGTRAP_HPP
