#include "../include/Form.hpp"

Form::Form() : name("default"),  sign(false), gradeRsign(1), gradeRex(1){
	std::cout << name << " Form constructor call" << std::endl;
}

Form::Form(std::string _name, int _gradeRsign, int _gradeRex): name(_name), sign(false), gradeRsign(_gradeRsign), gradeRex(_gradeRex)
{
	if (gradeRex > 150 || gradeRsign > 150)
		throw GradeTooLowExpectation();
	else if (gradeRex < 1 || gradeRsign < 1)
		throw GradeTooHightExpectation();
	std::cout << name << " Form constructor call" << std::endl;
}
Form::~Form() {
	std::cout << name << "Form destructor called" << std::endl;
}

Form::Form(const Form &other) : name(other.name), sign(other.sign), gradeRsign(other.gradeRsign), gradeRex(other.gradeRex) {
	std::cout << name << " Form copy constructor call" << std::endl;
	*this = other;
}

Form& Form::operator=(const Form &other) {
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return *this;
}

void Form::besigned(Bureaucrat &b)
{
	if(b.getGrade() > gradeRsign)
		throw GradeTooLowExpectation();
	else if (sign == true)
	{
		std::cout << name << " is already sign" << std::endl;
		return;
	}
	sign = true;
	std::cout << b.getName() << " signed " << name << std::endl;
}
bool		Form::isSign() const {return(sign);}
std::string	Form::getName() const {return(name);}
int			Form::getGsign() const {return(gradeRsign);}
int			Form::getGexec() const {return(gradeRex);}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
	os << b.getName() << ", Grade minimum for sign : " << b.getGsign()
	<< ", grade minimum for execut : " << b.getGexec()
	<< " , sign : " << b.isSign() << std::endl;
	return os;
}