#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(){
        std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
        std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) {
        std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
        *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
        std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
        if (this != &other) {
                (void)other;
        }
        return *this;
}
