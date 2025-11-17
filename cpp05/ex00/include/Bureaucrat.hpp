#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "../../color.hpp"
#include <iostream>
#include <exception>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);

	class GradeTooHightExpectation : public std::exception
	{
		public:
			const char* what() const noexcept override
			{
				return("GradetoHight catch");
			}
	};

	class GradeTooLowExpectation : public std::exception
	{
		public:
			const char* what() const noexcept override
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
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

#endif // BUREAUCRAT_HPP
