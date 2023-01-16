#include <stdint.h>
#include <iostream>

typedef struct Data
{
	int value;
}	Data;

uintptr_t serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int	main(void)
{
	Data obj;
	obj.value = 42;

	std::cout << "Original data: " << obj.value << std::endl;
	uintptr_t serialized = serialize(&obj);
	std::cout << "Serialized data: " << serialized << std::endl;
	Data *ptr = deserialize(serialized);
	std::cout << "Retrieved data: " << ptr->value << std::endl;
}

