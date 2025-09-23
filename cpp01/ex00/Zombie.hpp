#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:

		Zombie();
		Zombie(std::string name);
		~Zombie();
		std::string	getName();
		void		announce();

	private:

	std::string name;
};

Zombie*	newZombie( std::string name );
void	randomChump(std::string name);
#endif