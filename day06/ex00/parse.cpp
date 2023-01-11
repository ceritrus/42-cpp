#include <iostream>

bool strischar(std::string str)
{
	if ((int)str.length() == 1) // char are by definition one character long
		if (str[0] < '0' || str[0] > '9') // filter out single digit ints
			return true;
	return false;
}

bool strisint(std::string str)
{
	bool isdigit = true;
	for (int i = 0; i < (int)str.length() && isdigit; i++) // Iterate over string
	{
		if (i == 0 && str[i] == '-') // Skip minus sign
			continue;
		if (str[i] < '0' || str[0] > '9') // Look for non-digit chars
			isdigit = false;
	}
	return isdigit; // True if the string is made of digits exclusively
}

bool strisfloat(std::string str)
{
	if (str == "nanf" || str == "inff" || str == "-inff") // Float specifics
		return true;
	bool isnegative = false;
	bool isdigit = true;
	int i = -1;
	if (str[0] == '-')
	{
		isnegative = true;
		i++;
	}
	while (isdigit && ++i < (int)str.length()) // Iterate over string
	{
		if (str[i] < '0' || str[0] > '9') // Look for non-digit chars
			isdigit = false;
	}
	std::cout << "ratio" << std::endl;
	if (i >= (int)str.length() - 1)
		return false;
	std::cout << "out: " << str[i] << i << std::endl;
	if (str[i] == '.' && ((i >= 1 && !isnegative) || (i >= 2 && isnegative)))
	{
		isdigit = true;
		std::cout << "test" << std::endl;
		while (isdigit && ++i < (int)str.length()) // Iterate over string
		{
			std::cout << str[i];
			if (str[i] < '0' || str[0] > '9') // Look for non-digit chars
				isdigit = false;
		}
		std::cout << std::endl;
		std::cout << "allo: " << str[i] << i << std::endl;
		if (i == (int)str.length())
			return false;
		std::cout << "allo2" << std::endl;

		if (str[i] == 'f' && i == (int)str.length())
			return true;
	}
	return false;
}

bool strisdouble(std::string str)
{
	bool isnegative = false;
	bool isdigit = true;
	int i = -1;
	if (str[0] == '-')
	{
		isnegative = true;
		i++;
	}
	while (isdigit && ++i < (int)str.length()) // Iterate over string
	{
		if (str[i] < '0' || str[0] > '9') // Look for non-digit chars
			isdigit = false;
	}
	if (i >= (int)str.length() - 1)
		return false;
	if (str[i] == '.' && ((i > 1 && !isnegative) || (i > 2 && isnegative)))
	{
		isdigit = true;
		while (isdigit && ++i < (int)str.length()) // Iterate over string
		{
			if (str[i] < '0' || str[0] > '9') // Look for non-digit chars
				isdigit = false;
		}
		return isdigit;
	}
	return false;
}