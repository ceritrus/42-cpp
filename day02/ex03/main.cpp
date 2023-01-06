#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point a;
	Point b(10.0, 30.0);
	Point c(20.0, 0.0);
	Point d(10.0, 15.0);
	Point e(30.0, 15.0);
	Point f(20.0, 0.0);
	Point g(5.0, 15.0);
	Point h(12.3, 5.74);

	std::cout << "Let there be a triangle ABC such that A " << a << ", B " << b << " and C " << c << std::endl;
	std::cout << "Point D " << d << " " << (bsp(a, b, c, d)? "\e[92mis " : "\e[31mis not ") << "inside of triangle ABC\e[0m" << std::endl;
	std::cout << "Point E " << e << " " << (bsp(a, b, c, e)? "\e[92mis " : "\e[31mis not ") << "inside of triangle ABC\e[0m" << std::endl;
	std::cout << "Point F " << f << " " << (bsp(a, b, c, f)? "\e[92mis " : "\e[31mis not ") << "inside of triangle ABC\e[0m" << std::endl;
	std::cout << "Point G " << g << " " << (bsp(a, b, c, g)? "\e[92mis " : "\e[31mis not ") << "inside of triangle ABC\e[0m" << std::endl;
	std::cout << "Point H " << h << " " << (bsp(a, b, c, h)? "\e[92mis " : "\e[31mis not ") << "inside of triangle ABC\e[0m" << std::endl;
	return 0;
}