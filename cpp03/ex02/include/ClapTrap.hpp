#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iomanip> 
#include <iostream>
#include <thread>
#include <chrono>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

class ClapTrap
{
	public:
		ClapTrap(std::string _n);
		ClapTrap(std::string _n, int H, int E, int d);
		ClapTrap(const ClapTrap &cp);
		~ClapTrap();
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		setH_point(int H);
		void		setE_point(int E);
		void		set_damage(int d);
		std::string	getName() const;
		int			getH_point() const;
		int			getE_point() const;
		int			getDamage() const;

	private:
		std::string				name;
		unsigned int			H_point;
		unsigned int			E_point;
		unsigned int			damage ;
};
#endif