#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentPardonForm", 25, 5), target("test") {
        std::cout << target << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target): AForm("PresidentPardonForm", 25, 5), target(_target) {
        std::cout << target << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
        std::cout << target << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target){
        std::cout << target << "PresidentialPardonForm copy constructor called" << std::endl;
        *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
        std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
        if (this != &other) {
                (void)other;
        }
        return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor)
{
	if (executor.getGrade() > getGexec())
		throw GradeTooLowExpectation();
	if (isSign() == false)
		throw NotSign();
	std::cout << BOLDMAGENTA << target << " have been pardoned by Zaphod Beeblebrox " << RESET << std::endl;
}