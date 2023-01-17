#pragma once
#include <iostream>

template <typename Type>
void print(Type &val)
{
	std::cout << val << " ";
}

template <typename Type>
void increment(Type &val)
{
	val += 1;
}

template <typename Type>
void decrement(Type &val)
{
	val -= 1;
}

template <typename Type>
void nullify(Type &val)
{
	val = 0;
}

void squish(std::string &str)
{
	std::string output;
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) != ' ')
			output += str.at(i);
	}
	str = output;
}

template <typename Type>
Type increment(Type val)
{
	return val + 1;
}

template <typename Type> 
void iter(Type *arr, int len, void (*func)(Type&))
{
	for (int i = 0; i < len; i++)
		func(arr[i]);
}