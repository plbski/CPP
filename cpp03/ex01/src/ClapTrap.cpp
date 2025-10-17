#include"../include/ClapTrap.hpp"

void ClapTrap::printCharacterCard() {
    std::cout << BOLDBLUE
              << "\n=====================================\n"
              << "      🧙‍♂️  Character Card\n"
              << "=====================================\n"
              << RESET;

    std::cout << BOLDYELLOW << "Name:   " << RESET << name << "\n";

    std::cout << BOLDRED    << "HP:     " << RESET 
              << std::setw(3) << H_point << " ❤️\n";

    std::cout << BOLDGREEN  << "Damage: " << RESET 
              << std::setw(3) << damage << " 🗡️\n";

    std::cout << BOLDBLUE   << "Energy: " << RESET 
              << std::setw(3) << E_point << " ⚡\n";

    std::cout << BOLDBLUE
              << "=====================================\n"
              << RESET;
}

ClapTrap::ClapTrap(std::string _n): name(_n), H_point(10), E_point(10), damage(10)
{
	std::cout << "class ClapTrap " << name << " create" << std::endl;
	printCharacterCard();
};

ClapTrap::ClapTrap(std::string _n, int H, int E, int d):name(_n), H_point(H), E_point(E), damage(d)
{
	std::cout << "class ClapTrap " << name << " create" << std::endl;
	printCharacterCard();
}

ClapTrap::ClapTrap(const ClapTrap &cp): name(cp.name), H_point(cp.H_point), E_point(cp.E_point), damage(10)
{
	std::cout << "class ClapTrap " << name << " create by copy " << std::endl;
	printCharacterCard();
}

ClapTrap::~ClapTrap()
{
	std::cout << "class ClapTrap " << name << " destroye" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
	E_point --;
		std::cout << BOLDBLACK
          << "\n	   >>> " << this->getName() << " attack <<<\n"
          << "💥 inflicts " << this->getDamage() << " points damage to "
		  << target << "💥\n"
          << RESET << std::endl;
     std::cout << E_point << " energie remain" << std::endl;
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
          << "    🏥 recover " << amount << " points health 🏥\n"
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