#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp" 

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& input);
	~Point();

	Point& operator = (const Point& right);
	bool operator == (const Point& right) const;
	float getX() const;
	float getY() const;

	static float triangleArea(const Point a, const Point b, const Point c);
private:
	const Fixed _x;
	const Fixed _y;
};
std::ostream& operator << (std::ostream& out, const Point& right);

#endif