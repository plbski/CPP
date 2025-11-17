#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form {
public:
	Form();
	Form(std::string _name, int _gradeRsign, int _gradeRex);
	~Form();
	Form(const Form &other);
	Form& operator=(const Form &other);
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
	bool				sign = false;
	const int			gradeRsign;
	const int			gradeRex;
};

#endif // FORM_HPP
