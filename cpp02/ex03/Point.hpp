#ifndef POINT_CPP
#define POINT_CPP

#include "Fixed.hpp"

class Point 
{
	public :
		Point();
		Point(Fixed a, Fixed b);
		Point(const Point &_point);
		~Point();
		Fixed get_x();
		Fixed get_y();
		Fixed det(const Point &a, const Point &b) const;
	
	private:
		const Fixed x;
		const Fixed y;
};

#endif