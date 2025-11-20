#include <iostream>
#include "../include/Bureaucrat.hpp"

int main()
{
    std::cout << "===== TEST 1 : Constructeurs valides =====" << std::endl;
    try
    {
        Bureaucrat a("Alice", 1);
        Bureaucrat b("Bob", 42);
        Bureaucrat c("Charlie", 150);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception catch : " << e.what() << std::endl;
    }

    std::cout << std::endl << "===== TEST 2 : Constructeurs invalides =====" << std::endl;
    try
    {
        std::cout << "Création avec grade trop haut (0)..." << std::endl;
        Bureaucrat x("Xavier", 0); // devrait lancer GradeTooHightExpectation
        std::cout << x << std::endl; // ne sera pas exécuté
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception catch : " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Création avec grade trop bas (151)..." << std::endl;
        Bureaucrat y("Yvonne", 151); // devrait lancer GradeTooLowExpectation
        std::cout << y << std::endl; // ne sera pas exécuté
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception catch : " << e.what() << std::endl;
    }

    std::cout << std::endl << "===== TEST 3 : gradeUp() =====" << std::endl;
    try
    {
        Bureaucrat b("Bob", 3);
        std::cout << b << std::endl;

        std::cout << "gradeUp()" << std::endl;
        b.gradeUp();
        std::cout << b << std::endl;

        std::cout << "gradeUp()" << std::endl;
        b.gradeUp();
        std::cout << b << std::endl;

        std::cout << "gradeUp() encore (devrait lancer une exception si grade == 1)" << std::endl;
        b.gradeUp(); // ici, si ton implémentation est correcte, exception si grade < 1
        std::cout << b << std::endl; // ne devrait pas s'exécuter
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception catch : " << e.what() << std::endl;
    }

    std::cout << std::endl << "===== TEST 4 : gradeDown() =====" << std::endl;
    try
    {
        Bureaucrat c("Charlie", 149);
        std::cout << c << std::endl;

        std::cout << "gradeDown()" << std::endl;
        c.gradeDown();
        std::cout << c << std::endl;

        std::cout << "gradeDown()" << std::endl;
        c.gradeDown();
        std::cout << c << std::endl;

        std::cout << "gradeDown() encore (devrait lancer une exception si grade > 150)" << std::endl;
        c.gradeDown(); // devrait lancer GradeTooLowExpectation si tu bloques > 150
        std::cout << c << std::endl; // ne devrait pas s'exécuter
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception catch : " << e.what() << std::endl;
    }

    std::cout << std::endl << "===== TEST 5 : Copie et opérateur d’affectation =====" << std::endl;
    try
    {
        Bureaucrat original("Original", 10);
        std::cout << "Original : " << original << std::endl;

        Bureaucrat copie(original);
        std::cout << "Copie (constructeur de copie) : " << copie << std::endl;

        Bureaucrat assigné("Temp", 100);
        std::cout << "Avant affectation : " << assigné << std::endl;
        assigné = original;
        std::cout << "Après affectation : " << assigné << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception catch : " << e.what() << std::endl;
    }

    std::cout << std::endl << "===== FIN DES TESTS =====" << std::endl;
    return 0;
}
