#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string _n);
		ClapTrap(std::string _n, int H, int E, int d);
		ClapTrap(const ClapTrap &cp);
		~ClapTrap();
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		setH_point(int H);
		void		setE_point(int E);
		void		set_damage(int d);
		std::string	getName() const;
		int			getH_point() const;
		int			getE_point() const;
		int			getDamage() const;

	private:
		std::string				name;
		unsigned int			H_point;
		unsigned int			E_point;
		unsigned int			damage ;
};
#endif