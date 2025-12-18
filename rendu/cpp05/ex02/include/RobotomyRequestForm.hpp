#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm{
public:
    RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
    virtual~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
	virtual void	execute(Bureaucrat const &executor);

private:
	const std::string target;
};

#endif // ROBOTOMYREQUESTFORM_HPP
