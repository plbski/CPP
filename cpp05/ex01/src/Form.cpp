#include "../include/Form.hpp"

Form::Form() : name("default"), gradeRex(1), gradeRsign(1) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string _name, int _gradeRsign, int _gradeRex): name(_name), gradeRsign(_gradeRsign), gradeRex(_gradeRex)
{
	std::cout << "Form default constructor called" << std::endl;
}
Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &other) : name(other.name), sign(other.sign), gradeRsign(other.gradeRsign), gradeRex(other.gradeRex) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = other;
}

Form& Form::operator=(const Form &other) {
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return *this;
}

void Form::besigned(const Bureaucrat &b)
{
	if(b.getGrade() > gradeRsign)
		throw GradeTooHightExpectation();
	sign = true;
}

std::string Form::getName()const {return(name);}