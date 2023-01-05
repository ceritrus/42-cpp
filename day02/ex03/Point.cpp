#include "Point.hpp"

Point::Point()
	:_x(0), _y(0)
{

}

Point::Point(const float x, const float y)
	:_x(x), _y(y)
{

}

Point::Point(const Point& input)
	:_x(input._x), _y(input._y)
{

}

Point::~Point()
{

}

Point& Point::operator=(const Point& right)
{
	(void)right;
	std::cout << "Assignment of const variables impossible" << std::endl;
	return *this;
}

bool Point::operator==(const Point& right) const
{
	if (_x == right._x && _y == right._y)
		return true;
	else
		return false;
}

float Point::getX() const
{
	return _x.toFloat();
}

float Point::getY() const
{
	return _y.toFloat();
}

float Point::triangleArea(const Point a, const Point b, const Point c)
{
	float tempA = a.getX() * (b.getY() - c.getY());
	float tempB = b.getX() * (c.getY() - a.getY());
	float tempC = c.getX() * (a.getY() - b.getY());
	float area = fabs(tempA + tempB + tempC)/2.0;
	return area;
}


std::ostream& operator<<(std::ostream& out, const Point& right)
{
	out << "\e[93m(" << right.getX() << ", " << right.getY() << ")\e[0m";
	return out;
}