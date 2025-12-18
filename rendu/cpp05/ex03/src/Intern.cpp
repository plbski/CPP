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
	std::string form[3] = {"shrubbery request", "robotomy request", "presidential pardon"};
	AForm* (*create[3])(std::string) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresident
	};

	while (i < 3){
		if (form[i] == name)
			return(create[i](target));
		i ++;
	}
	std::cout << BOLDRED << "please enter correct form :\nshrubbery request\nrobotomy request\npresidential pardon"
	<< RESET << std::endl;
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


