#ifndef CLAPTRAP_HPP
#define CLAAPTRAP_CPP

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string _n);
		ClapTrap(const ClapTrap &cp);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string	name;
		unsigned int			H_point;
		unsigned int			E_point;
		unsigned int			damage ;
};
#endif