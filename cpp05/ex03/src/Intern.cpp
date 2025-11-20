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
	AForm *func[] = {&ShrubberyCreationForm , &RobotomyRequestForm, &PresidentialPardonForm};
	while (i < 3){
		i ++;}
	if (form[i] == name)
	{
		return(func[i](target));
	}
	std::cout << " please enter correct form :\n shrubbery request\nrobotomy request\npresidential pardon"<< std::endl;
	return(NULL);
}