#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "../../color.hpp"
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);
	void	signAForm(AForm &f);

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

	std::string	getName() const;
	int			getGrade() const;
	void		gradeUp();
	void		gradeDown();

private:
	int grade;
	const std::string name;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif // BUREAUCRAT_HPP
