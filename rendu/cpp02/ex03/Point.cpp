#include "Point.hpp"

Point::Point(){}

Point::Point(Fixed const a, Fixed const b): x(a), y(b){}

Point::Point(const Point &point): x(point.x), y(point.y){}

Point::~Point(){};

Fixed Point::det(const Point &p2, const Point &p3) const
{
	return (x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (y - p3.y);
}
