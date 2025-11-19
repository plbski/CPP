#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("test") {
        std::cout << target << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm", 72, 45), target(_target) {
        std::cout << target << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
        std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), target(other.target) {
        std::cout << target << "RobotomyRequestForm copy constructor called" << std::endl;
        *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
        std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
        if (this != &other) {
                (void)other;
        }
        return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor)
{
	if (executor.getGrade() > getGexec())
		throw GradeTooLowExpectation();
	if (isSign() == false)
		throw NotSign();
	std::cout << BOLDYELLOW << "DRRRRRR....INGGGGGGGG....DRRRRRRR " << std::endl;
	std::srand(time(0));
	if(std::rand()%2 == 1)
		std::cout << BOLDGREEN<< "has been robotomized" << RESET << std::endl;
	else
		std::cout << BOLDRED << "robotomy failed" << RESET << std::endl;
}