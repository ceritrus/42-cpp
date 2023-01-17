#pragma once

template <typename Type>
class Array
{
private:
	Type *arr;
	uint size;
public:
	Array();
	Array(uint n);
	Array(Array copy);
	~Array();

	Array operator=()
};