#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (point == a || point == b || point == c)
		return false;

	float ABC = Point::triangleArea(a, b, c);

	float PAB = Point::triangleArea(point, a, b);
	float PBC = Point::triangleArea(point, b, c);
	float PAC = Point::triangleArea(point, a, c);

	if (PAB == 0.0 || PBC == 0.0 || PAC == 0.0)
		return false;

	float total = PAB + PBC + PAC;

	if (total == ABC)
		return true;
	else
		return false;
}