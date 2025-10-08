#include"HumanB.hpp"

HumanB::HumanB(std::string name):_weapon(NULL)
{
	this->name = name;
}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon& w)
{
	this->_weapon = &w;
}
void HumanB::attack()
{
	if (!_weapon)
		std::cout << "no weapon equiped " <<std::endl;
	else
		std::cout << this->name << " attacks with their " << this->_weapon->getType() << std::endl;
} 