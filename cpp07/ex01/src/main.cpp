#include "../include/template.hpp"

void afficherInt(int x)
{
    std::cout << x << " ";
}

void afficherDouble(const double x)
{
    std::cout << x << " ";
}

void afficherChar(char c)
{
    std::cout << c << " ";
}

// ====== MAIN DE TEST ======

int main()
{
    std::cout << "===== TEST AVEC INT =====\n";
    const int tabInt[] = {1, 2, 3, 4, 5};
    int sizeInt = 5;

    iter(tabInt, sizeInt, afficherInt);
    std::cout << "\n\n";

    std::cout << "===== TEST AVEC DOUBLE =====\n";
    double tabDouble[] = {1.1, 2.2, 3.3, 4.4};
    int sizeDouble = 4;

    iter(tabDouble, sizeDouble, afficherDouble);
    std::cout << "\n\n";

    std::cout << "===== TEST AVEC CHAR =====\n";
    char tabChar[] = {'H', 'e', 'l', 'l', 'o'};
    int sizeChar = 5;

    iter(tabChar, sizeChar, afficherChar);
    std::cout << "\n";

    return 0;
}