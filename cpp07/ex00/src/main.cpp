#include "../include/template.hpp"

int main()
{
	std::cout << "===== TEST AVEC INT =====\n";
	int a = 30, b = 25;

	std::cout << "Avant swap : a = " << a << ", b = " << b << '\n';
	::swap(a, b);
	std::cout << "Apres swap : a = " << a << ", b = " << b << '\n';

	std::cout << "max(a, b) = " << ::max(a, b) << '\n';
	std::cout << "min(a, b) = " << ::min(a, b) << '\n';


	std::cout << "\n===== TEST AVEC DOUBLE =====\n";
	double x = 3.5, y = 1.2;

	std::cout << "Avant swap : x = " << x << ", y = " << y << '\n';
	::swap(x, y);
	std::cout << "Apres swap : x = " << x << ", y = " << y << '\n';

	std::cout << "max(x, y) = " << ::max(x, y) << '\n';
	std::cout << "min(x, y) = " << ::min(x, y) << '\n';


	std::cout << "\n===== TEST AVEC STRING =====\n";
	std::string s1 = "chaine1";
	std::string s2 = "chaine2";

	std::cout << "Avant swap : s1 = " << s1 << ", s2 = " << s2 << '\n';
	::swap(s1, s2);
	std::cout << "Apres swap : s1 = " << s1 << ", s2 = " << s2 << '\n';

	std::cout << "max(s1, s2) = " << ::max(s1, s2) << '\n'; // comparaison alphabétique
	std::cout << "min(s1, s2) = " << ::min(s1, s2) << '\n';


	std::cout << "\n✅ Tous les tests sont termines.\n";

	return 0;
}