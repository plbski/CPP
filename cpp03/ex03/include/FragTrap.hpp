#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap &cp);
    ~FragTrap();
	void		HighFiveGuys();

protected:
	static const int base_HP = 100;
	static const int base_E = 100;
	static const int base_D = 30;

};

#endif // FRAGTRAP_HPP
