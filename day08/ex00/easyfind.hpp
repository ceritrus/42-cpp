#pragma once

#include <iostream>

template <typename Type> 
typename Type::iterator easyfind(Type &arr, int tofind)
{
	for (typename Type::iterator iter = arr.begin(); iter < arr.end(); iter++)
	{
		if (*iter == tofind)
			return iter;
	}
	std::cerr << "Easyfind: value not found" << std::endl;
	return arr.end();
}