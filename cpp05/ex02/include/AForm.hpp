#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>

class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(std::string _name, int _gradeRsign, int _gradeRex);
	~AForm();
	AForm(const AForm &other);
	AForm&			operator=(const AForm &other);
	void			besigned(Bureaucrat &b);
	std::string		getName() const;
	int				getGexec() const ;
	int				getGsign() const;
	bool			isSign() const;
	virtual void	execute(Bureaucrat const &executor) = 0;

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

	class NotSign : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return("Form not sign catch");
			}
	};

private:
	const std::string	name;
	bool				sign;
	const int			gradeRsign;
	const int			gradeRex;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif // AForm_HPP
