#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "HumanA.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon w);
	
	private:
		std::string name;
		Weapon* _weapon = NULL;
};

#endif