#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
	virtual void	execute(Bureaucrat const &executor);

private:
	const std::string target;
};

#endif // SHRUBBERYCREATIONFORM_HPP
