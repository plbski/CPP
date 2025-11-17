#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
public:
	Form();
	Form(std::string _name, int _gradeRsign, int _gradeRex);
	~Form();
	Form(const Form &other);
	Form&		operator=(const Form &other);
	void		besigned(const Bureaucrat &b);
	std::string	getName() const;
	int			getGexec() const ;
	int			getGsign() const;

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

#endif // FORM_HPP
