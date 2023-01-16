#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

bool strischar(std::string str);
bool strisint(std::string str);
bool strisfloat(std::string str);
bool strisdouble(std::string str);

void display(char c)
{
	std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void display(int n)
{
	if (std::isprint(n) == 0)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void display(float f)
{
	if (isnan(f) || isinf(f))
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
	}
	else
	{
		if (std::isprint(static_cast<int>(f)) == 0)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	std::cout << "float: " << f << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void display(double d)
{
	if (isnan(d) || isinf(d))
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
	}
	else
	{
		if (std::isprint(static_cast<int>(d)) == 0)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " << d << std::endl;
}

void display()
{
	std::cout <<  "char: Impossible" << std::endl;
	std::cout <<  "int: Impossible" << std::endl;
	std::cout <<  "float: Impossible" << std::endl;
	std::cout <<  "double: Impossible" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: argument missing" << std::endl;
		return 1;
	}
	else if (argc > 2)
	{
		std::cerr << "Error: too many arguments" << std::endl;
		return 1;
	}
	std::cout << std::fixed << std::setprecision(2);
	std::string input = std::string(argv[1]);
	if (strischar(input))
		display(input[0]);
	else if (strisint(input))
		display(std::stoi(input));
	else if (strisfloat(input))
		display(std::stof(input));
	else if (strisdouble(input))
		display(std::stod(input));
	else
		display();
	return 0;
}