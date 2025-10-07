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
	Point a (0, -1);
	Point const b (10.0f , 2);
	Point c(-10.0f, 2);

	Point inside (0, 0);
	Point outside(-2, -2);

	std::cout << "expected inside" << std::endl;
	if (bsp(a, b, c, inside))
		std::cout << "the point is inside" << std::endl;
	else
		std::cout << "point is outside" << std::endl;
	std::cout << "expected outside" << std::endl;
	if (bsp(a, b, c, outside))
		std::cout << "point is inside" << std::endl;
	else
		std::cout << "point is outside" << std::endl;
	return(0);
}