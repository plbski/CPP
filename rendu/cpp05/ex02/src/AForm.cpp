#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() : name("default"),  sign(false), gradeRsign(1), gradeRex(1){
	std::cout << name << " AForm constructor call" << std::endl;
}

AForm::AForm(std::string _name, int _gradeRsign, int _gradeRex): name(_name), sign(false), gradeRsign(_gradeRsign), gradeRex(_gradeRex)
{
	if (gradeRex > 150 || gradeRsign > 150)
		throw GradeTooLowExpectation();
	else if (gradeRex < 1 || gradeRsign < 1)
		throw GradeTooHightExpectation();
	std::cout << name << " AForm constructor call" << std::endl;
}
AForm::~AForm() {
	std::cout << name << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), sign(other.sign), gradeRsign(other.gradeRsign), gradeRex(other.gradeRex) {
	std::cout << name << " AForm copy constructor call" << std::endl;
	*this = other;
}

AForm& AForm::operator=(const AForm &other) {
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return *this;
}

void AForm::besigned(Bureaucrat &b)
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
bool		AForm::isSign() const {return(sign);}
std::string	AForm::getName() const {return(name);}
int			AForm::getGsign() const {return(gradeRsign);}
int			AForm::getGexec() const {return(gradeRex);}

std::ostream& operator<<(std::ostream& os, const AForm& b)
{
	os << b.getName() << ", Grade minimum for sign : " << b.getGsign()
	<< ", grade minimum for execut : " << b.getGexec()
	<< " , sign : " << b.isSign() << std::endl;
	return os;
}