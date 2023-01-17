#pragma once

template <typename Type>
Type max(Type a, Type b)
{
	return (a > b) ? a : b;
}

template <typename Type>
Type min(Type a, Type b)
{
	return (a < b) ? a : b;
}

template <typename Type>
void swap(Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b = temp;
}