#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("test"){
        std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

	ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", 145, 137), target(_target){
		std::cout << target << "ShrubberyCreationForm default constructor called" << std::endl;
	}
ShrubberyCreationForm::~ShrubberyCreationForm() {
        std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) {
        std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
        *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
        std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
        if (this != &other) {
                (void)other;
        }
        return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	if (executor.getGrade() > getGexec())
		throw GradeTooLowExpectation();
	if (isSign() == false)
		throw NotSign();
	std::ofstream file(target.c_str());

	file << "      /\\      " << std::endl;
	file << "     /  \\     " << std::endl;
	file << "    /++++\\    " << std::endl;
	file << "   /  ++  \\   " << std::endl;
	file << "  /        \\  " << std::endl;
	file << "     ||||      " << std::endl;

	file.close();
}