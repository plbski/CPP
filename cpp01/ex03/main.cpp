#include "HumanB.hpp"


int main()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	Weapon test = Weapon("tes");
	HumanB jj("gg");
	jj.setWeapon(test);
	jj.attack();
return (0);
}
