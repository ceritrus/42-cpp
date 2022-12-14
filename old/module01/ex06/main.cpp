#include "Harl.hpp"

int main(int argc, char** argv)
{
	if (argc > 2)
	{
		std::cerr << "Error: too namy parameters [" << argc - 1 << " > 1]" << std::endl;
		return 1;
	}
	if (argc < 2)
	{
		std::cerr << "Error: not enough parameters [" << argc - 1 << " < 1]" << std::endl;
		return 1;
	}
	Harl harl;
	
	harl.filter(argv[1]);
}