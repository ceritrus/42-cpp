#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./pmergeme [list of positive integers]" << std::endl;
		return 1;
	}

	PmergeMe merger(argc, argv);
	merger.Compute();
}