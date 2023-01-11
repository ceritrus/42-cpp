#include <iostream>
#include <string>

bool strischar(std::string str);
bool strisint(std::string str);
bool strisfloat(std::string str);
bool strisdouble(std::string str);

void display(double d)
{
	std::cout << "double: " << d << std::endl;
}

void display(char c)
{
	std::cout << "char: " << c << std::endl;
}

void display(int n)
{
	std::cout << "int: " << n << std::endl;
}

void display(float f)
{
	std::cout << "float: " << f << std::endl;
}

void display()
{
	std::cout <<  "char: impossible" << std::endl;
	std::cout <<  "int: impossible" << std::endl;
	std::cout <<  "float: impossible" << std::endl;
	std::cout <<  "double: impossible" << std::endl;
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