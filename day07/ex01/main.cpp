#include "iter.hpp"
#include <iostream>
int main(void)
{
	std::cout << "###############################" << std::endl;
	{
		int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		iter(arr, 10, print);
		std::cout << std::endl;

		iter(arr, 10, increment);
		iter(arr, 10, print);
		std::cout << std::endl;

		iter(arr, 10, nullify);
		iter(arr, 10, print);
		std::cout << std::endl;

	}
	std::cout << "###############################" << std::endl;
	{
		char tab[] = {'I', 'f', 'm', 'm', 'p', '-', '!', 'X', 'p', 's', 'm', 'e'};
		iter(tab, 12, print);
		std::cout << std::endl;

		iter(tab, 12, decrement);
		iter(tab, 12, print);
		std::cout <<  std::endl;
	}
	std::cout << "###############################" << std::endl;
	{
		std::string stringTab[] = {"S a l u t", " t o      i ", " a u ", " revoir "};
		iter(stringTab, 4, print);
		std::cout <<  std::endl;
		
		iter(stringTab, 4, squish);
		iter(stringTab, 4, print);
		std::cout <<  std::endl;
	}
	std::cout << "###############################" << std::endl;
}