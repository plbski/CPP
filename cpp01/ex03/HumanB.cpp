#include"HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon w)
{
	this->_weapon = &w;
}
void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->_weapon->getType() << std::endl;
}