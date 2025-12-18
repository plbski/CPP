#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main()
{
    std::cout << "===== INTERN FORM CREATION TESTS =====" << std::endl;

    Intern intern;
    AForm *form;

    std::cout << "\n--- Test 1: Create a ShrubberyCreationForm ---" << std::endl;
    form = intern.makeForm("shrubbery request", "home");

    if (form)
        std::cout << "Form successfully created: " << form->getName() << std::endl;
    else
        std::cout << "Form creation failed." << std::endl;

    std::cout << "\n--- Test 2: Create an unknown form ---" << std::endl;
    AForm *badForm = intern.makeForm("unknown form", "test");

    if (!badForm)
        std::cout << "Unknown form correctly rejected." << std::endl;

    std::cout << "\n===== BUREAUCRAT SIGN/EXECUTE TESTS =====" << std::endl;

    try
    {
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;

        if (form)
        {
            std::cout << "\n--- Test 3: Boss tries to sign the form ---" << std::endl;
            form->besigned(boss);
            std::cout << "Form is now signed." << std::endl;

            std::cout << "\n--- Test 4: Boss executes the form ---" << std::endl;
            form->execute(boss);
            std::cout << "Form executed successfully." << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n===== ERROR HANDLING TESTS =====" << std::endl;

    try
    {
        Bureaucrat lowRank("LowRank", 150);
        ShrubberyCreationForm shrub("garden");

        std::cout << lowRank << std::endl;
        std::cout << "\n--- Test 5: LowRank tries to sign ---" << std::endl;

        shrub.besigned(lowRank);  // should throw
    }
    catch (std::exception &e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat medium("MediumGuy", 100);
        ShrubberyCreationForm shrub2("forest");

        std::cout << "\n--- Test 6: Execute without signing ---" << std::endl;
        shrub2.execute(medium);  // should throw
    }
    catch (std::exception &e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== END OF TESTS =====" << std::endl;
    return 0;
}


