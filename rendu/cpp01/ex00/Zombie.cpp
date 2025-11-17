# include "Zombie.hpp"

Zombie::Zombie(){};

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " has been destroyed" <<std::endl;
}

std::string Zombie::getName(){return (this->name);}

void Zombie::announce()
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..."<< std::endl;
}
