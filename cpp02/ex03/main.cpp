#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed b1 = a.det(point, b);
	Fixed b2 = c.det(point, a);
	Fixed b3 = b.det(point, c);

	if ((b1 < 0 && b2 < 0 && b3 < 0) || (b1 > 0 && b2 > 0 && b3 > 0))
		return(1);
	return(0);
}
int main()
{
	Point a (Fixed (0), Fixed (-1));
	Point const b (Fixed(10.0f), Fixed(2));
	Point c(Fixed(-10.0f), Fixed(2));
	Point p (Fixed (0) , Fixed (0));
	if (bsp(a, b, c, p))
		std::cout << "p est dedans" << std::endl;
	else
		std::cout << "p est dehors" << std::endl;
	return(0);
}