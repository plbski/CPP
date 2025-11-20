#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
    std::cout << "===== TEST 1 : Shrubbery signé + exécuté par un bon grade =====" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);                 // très bon grade
        ShrubberyCreationForm shrub("home");        // target = "home"
		ShrubberyCreationForm test(shrub);
		AForm *rrf = new RobotomyRequestForm("li");

		std::cout << *rrf << std::endl;
        std::cout << boss << std::endl;
        std::cout << shrub << std::endl;
		std::cout << test << std::endl;

        std::cout << "\n-> Boss sign the form" << std::endl;
        shrub.besigned(boss);                       // doit réussir

        std::cout << "\n-> Boss executed form" << std::endl;
        shrub.execute(boss);                        // doit réussir (création du fichier, etc.)

        std::cout << "\nExecution succed" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception catch (TEST 1) : " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2 : exécution sans signature =====" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrub2("garden");

        std::cout << bob << std::endl;
        std::cout << shrub2 << std::endl;

        std::cout << "\n-> Bob try to execute without sign" << std::endl;
        shrub2.execute(bob);                        // doit lancer NotSign
    }
    catch (std::exception &e)
    {
        std::cout << "Exception catch (TEST 2) : " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3 : grade trop bas pour exécuter =====" << std::endl;
    try
    {
        Bureaucrat low("Intern", 150);              // très mauvais grade
        ShrubberyCreationForm shrub3("yard");

        std::cout << low << std::endl;
        std::cout << shrub3 << std::endl;

        std::cout << "\n-> Intern sign the form (si autorisé)" << std::endl;
        shrub3.besigned(low);                       // selon tes règles, peut déjà échouer ici

        std::cout << "\n-> Intern try to execute" << std::endl;
        shrub3.execute(low);                        // doit lancer GradeTooLowExpectation
    }
    catch (std::exception &e)
    {
        std::cout << "Exception catch (TEST 3) : " << e.what() << std::endl;
    }

	std::cout << "\n===== TEST 4 : Robotomy signé + exécuté par un bon grade =====" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);                 // très bon grade
        RobotomyRequestForm shrub("home");        // target = "home"

        std::cout << boss << std::endl;
        std::cout << shrub << std::endl;

        std::cout << "\n-> Boss sign the form" << std::endl;
        shrub.besigned(boss);                       // doit réussir

        std::cout << "\n-> Boss executed form" << std::endl;
        shrub.execute(boss);                        // doit réussir (création du fichier, etc.)

        std::cout << "\nExecution succed" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception catch (TEST 1) : " << e.what() << std::endl;
    }

	std::cout << "\n===== TEST 5 : Presidential pardon signé + exécuté par un bon grade =====" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);                 // très bon grade
        PresidentialPardonForm shrub("home");        // target = "home"

        std::cout << boss << std::endl;
        std::cout << shrub << std::endl;

        std::cout << "\n-> Boss sign the form" << std::endl;
        shrub.besigned(boss);                       // doit réussir

        std::cout << "\n-> Boss executed form" << std::endl;
        shrub.execute(boss);                        // doit réussir (création du fichier, etc.)

        std::cout << "\nExecution succed" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception catch (TEST 1) : " << e.what() << std::endl;
    }
    std::cout << "\n===== FIN DES TESTS =====" << std::endl;
    return 0;
}

