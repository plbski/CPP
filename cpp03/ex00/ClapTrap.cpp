#include"ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _n): name(_n), H_point(10), E_point(10), damage(10)
{
	std::cout << "class " << name << " create" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &cp): name(cp.name), H_point(cp.H_point), E_point(cp.E_point), damage(10)
{
	std::cout << "class " << name << " create by copy " << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "class " << name << " destroye" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	E_point --;
	std::cout<< name << " attacked " << target << " causing " << damage << " point damage\nHealth point : " << H_point << std::endl;
	std::cout << E_point << " energie remain" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= H_point)
	{
		std::cout << name << " is dead" <<std::endl;
		H_point = 0;
		return;
	}
	H_point -= amount;
	std::cout<< name << " take " << amount << " point damage\nHealth point : " << H_point << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (H_point == 10)
	{
		std::cout << "no repair needed " << std::endl;
		return;
	}	
	E_point --;
	H_point += amount;
	if (H_point > 10)
		H_point = 10;
	std::cout<< name << " recover " << amount << " health point\nHealth point : " << H_point << std::endl;
	std::cout << E_point << " energie remain" << std::endl;
}