#include"../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _n): name(_n), H_point(10), E_point(10), damage(10)
{
	std::cout << "class ClapTrap" << name << " create" << std::endl;
};

ClapTrap::ClapTrap(std::string _n, int H, int E, int d):name(_n), H_point(H), E_point(E), damage(d)
{
	std::cout << "class ClapTrap" << name << " create" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cp): name(cp.name), H_point(cp.H_point), E_point(cp.E_point), damage(10)
{
	std::cout << "class ClapTrap" << name << " create by copy " << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "class ClapTrap" << name << " destroye" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
	E_point --;
		std::cout << BOLDBLACK
          << "\n	   >>> " << this->getName() << " attack <<<\n"
          << "💥 inflicts " << this->getDamage() << " points damage to "
		  << target << "💥\n"
          << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
		std::cout << BOLDRED
          << "\n	  >>> " << this->getName() << " <<<\n"
          << "    🩸 take " << amount << " points damage 🩸\n"
          << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{	
	E_point --;
	H_point += amount;
	std::cout << BOLDYELLOW
          << "\n	   >>> " << this->getName() << " <<<\n"
          << "    🏥 recover" << amount << " points health 🏥\n"
          << RESET << std::endl;
	std::cout << E_point << " energie remain" << std::endl;
}

void	ClapTrap::setH_point(int H){H_point = H;}
void	ClapTrap::setE_point(int E){E_point = E;}
void	ClapTrap::set_damage(int d){damage = d;}

std::string ClapTrap::getName() const {return (name);}
int ClapTrap::getH_point() const {return(H_point);}
int ClapTrap::getE_point() const {return(E_point);}
int ClapTrap::getDamage() const {return(damage);}