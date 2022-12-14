#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Fixed::setVerbose(false);
	
	Point a;
	Point b(10.0, 30.0);
	Point c(20.0, 0.0);
	Point d(10.0, 15.0);
	Point e(30.0, 15.0);
	Point f(20.0, 0.0);
	Point g(5.0, 15.0);
	Point h(12.3, 5.74);

	std::cout << "Let the coordinates of three corners of a triangle A" << a << ", B " << b << " and C " << c << std::endl;
	std::cout << "Point D " << d << " is inside of triangle ABC: " << (bsp(a, b, c, d)? "true": "false")  << std::endl;
	std::cout << "Point E " << e << " is inside of triangle ABC: " << (bsp(a, b, c, e)? "true": "false") << std::endl;
	std::cout << "Point F " << f << " is inside of triangle ABC: " << (bsp(a, b, c, f)? "true": "false") << std::endl;
	std::cout << "Point G " << g << " is inside of triangle ABC: " << (bsp(a, b, c, g)? "true": "false") << std::endl;
	std::cout << "Point H " << h << " is inside of triangle ABC: " << (bsp(a, b, c, h)? "true": "false") << std::endl;
	return 0;
}