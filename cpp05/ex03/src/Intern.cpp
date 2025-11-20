#include "../include/Intern.hpp"

Intern::Intern(){
        std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern() {
        std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
        std::cout << "Intern copy constructor called" << std::endl;
        *this = other;
}

Intern& Intern::operator=(const Intern &other) {
        std::cout << "Intern copy assignment operator called" << std::endl;
        if (this != &other) {
                (void)other;
        }
        return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	int i = 0;
	std::string form[] = {"shrubbery request", "robotomy request", "presidential pardon"};
	AForm* (*create[3])(std::string) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresident
	};

	while (i < 3){
		i ++;	if (form[i] == name)
		{
			i ++;
			return(create[i](target));
		}
	}
	std::cout << " please enter correct form :\n shrubbery request\nrobotomy request\npresidential pardon"<< std::endl;
	return(NULL);
}

AForm* Intern::makeShrubbery(std::string target){
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(std::string target){
	return(new RobotomyRequestForm(target));
}
 AForm *Intern::makePresident(std::string target){
	return(new PresidentialPardonForm(target));
}


