#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "../../color.hpp"
#include <iostream>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);
	class GradeTooHightExpectation : public std::exception
	{

	};
	void		GradeTooLowExpectation();
	std::string	getName();
	std::string	getGrade();
	void		gradeUp();
	void		gradeDown();

private:
	int grade;
	const std::string name;
};

#endif // BUREAUCRAT_HPP
