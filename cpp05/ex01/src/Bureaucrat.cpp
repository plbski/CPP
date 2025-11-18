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
	std::cout << name << " Bureaucrat constructor call" << std::endl;
}
Bureaucrat::~Bureaucrat() {
	std::cout << name << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): grade(other.grade), name(other.name) {
	std::cout << name << " Bureaucrat copy constructor call" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other) {
		this->grade = other.grade;
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

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.besigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " could not sign " << f.getName()
		<< " because " << e.what() << std::endl;
	}
}
	

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}