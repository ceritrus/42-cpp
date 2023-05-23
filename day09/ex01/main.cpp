#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "usage: ./rpn \"<expression>\"" << std::endl;
		return 1;
	}

	try 
	{
		std::string str = argv[1];
		RPN rpn(str);
		std::cout << rpn.compute() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}