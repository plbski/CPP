#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *greg;
	greg = new Zombie(name);
	return (greg);
}