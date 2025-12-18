#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form();
	Form(std::string _name, int _gradeRsign, int _gradeRex);
	~Form();
	Form(const Form &other);
	Form&		operator=(const Form &other);
	void		besigned(Bureaucrat &b);
	std::string	getName() const;
	int			getGexec() const ;
	int			getGsign() const;
	bool		isSign() const;

	class GradeTooHightExpectation : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return("GradetoHight catch");
			}
	};

	class GradeTooLowExpectation : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return("GradetoLow catch");
			}
	};
private:
	const std::string	name;
	bool				sign;
	const int			gradeRsign;
	const int			gradeRex;
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif // Form_HPP
