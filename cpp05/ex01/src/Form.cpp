#include "../include/Form.hpp"

Form::Form() : name("default"), gradeRex(1), gradeRsign(1), sign(false){
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string _name, int _gradeRsign, int _gradeRex): name(_name), gradeRsign(_gradeRsign), gradeRex(_gradeRex), sign(false)
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

std::string	Form::getName() const {return(name);}
int			Form::getGsign() const {return(gradeRsign);}
int			Form::getGexec() const {return(gradeRsign);}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
	os << b.getName() << ", Grade minimum for sign : " << b.getGsign() << ", grade minimum for execut : " << b.getGexec() << std::endl;
	return os;
}