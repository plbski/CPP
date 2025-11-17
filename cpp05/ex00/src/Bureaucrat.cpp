#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : grade(_grade), name(_name)
{
	if (_grade > 150)
		throw GradeTooHightExpectation();
	else if (_grade < 1)
		throw GradeTooLowExpectation();
}
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return *this;
}

int Bureaucrat::getGrade() const{return(grade);}

std::string Bureaucrat::getName() const{return(name);}

void Bureaucrat::gradeDown()
{
	if (grade + 1 > 150)
		throw GradeTooLowExpectation();
	grade ++;
}

void Bureaucrat::gradeUp()
{
	if (grade - 1 < 1)
		throw GradeTooHightExpectation();
	grade --;
}
