#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "===== TEST 1 : Construction de Form valides =====" << std::endl;
    try
    {
        Form f1("Form_A", 50, 25);
        Form f2("Form_B", 1, 1);
        Form f3("Form_C", 150, 150);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée (TEST 1) : " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "===== TEST 2 : Construction de Form invalides =====" << std::endl;

    try
    {
        std::cout << "Essai Form gradeRsign = 0..." << std::endl;
        Form bad1("BadForm1", 0, 10); // trop haut
        std::cout << bad1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée (BadForm1) : " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Essai Form gradeRex = 151..." << std::endl;
        Form bad2("BadForm2", 10, 151); // trop bas
        std::cout << bad2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée (BadForm2) : " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "===== TEST 3 : Bureaucrat signe un Form (succès) =====" << std::endl;

    try
    {
        Bureaucrat bob("Bob", 40);           // 1 = top, 150 = nul
        Form      f("Form_OK", 50, 20);      // il faut 50 pour signer

        std::cout << bob << std::endl;
        std::cout << f << std::endl;

        bob.signForm(f);                     // doit marcher
        std::cout << f << std::endl;         // devrait être signé
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée (TEST 3) : " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "===== TEST 4 : Bureaucrat trop bas essaie de signer =====" << std::endl;

    try
    {
        Bureaucrat jim("Jim", 120);          // grade trop bas
        Form      f("ImportantForm", 50, 20);

        std::cout << jim << std::endl;
        std::cout << f << std::endl;

        jim.signForm(f);                     // doit échouer (beSigned lance GradeTooLowExpectation)
        std::cout << f << std::endl;         // si tu affiches isSigned dedans, tu verras que c'est faux
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée (TEST 4) : " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "===== TEST 5 : Form déjà signé =====" << std::endl;

    try
    {
        Bureaucrat alice("Alice", 10);
        Form      f("OnceOnly", 20, 20);

        std::cout << alice << std::endl;
        std::cout << f << std::endl;

        alice.signForm(f);                   // 1ère fois : OK
        alice.signForm(f);                   // 2ème fois : à toi de décider (message ou just ignore)
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée (TEST 5) : " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "===== FIN DES TESTS =====" << std::endl;

    return 0;
}
