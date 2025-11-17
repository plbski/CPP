#ifndef WEAPON_HPP
# define WAEPON_HPP

#include<string>
#include<iostream>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		std::string	getType();
		void		setType(std::string type);
	
	private:
		std::string type;

};
#endif