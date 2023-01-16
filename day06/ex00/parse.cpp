#include <iostream>

#define NPOS std::string::npos

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

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
	size_t start = str.find_first_of('-');
	size_t point = str.find_first_of('.');
	size_t fpos = str.find_first_of('f');
	
	// Compare to float-specific values
	if (str == "nanf" || str == "inff" || str == "-inff")
		return true;
	// std::cerr << "No specific" << std::endl;

	// Check if there is no point(.) or float char(f)
	if (point == NPOS || fpos == NPOS)
		return false;
	// std::cerr << "Point and float identifier found" << std::endl;

	// Check if multiple/invalid minus sign(s) (invalid: not str[0])
	if (start != str.find_last_of('-') || (start != NPOS && start != 0))
		return false;
	start = (start == NPOS) ? 0 : start + 1;
	// std::cerr << "Valid/No minus sign: " << str.substr(start, point - start) << std::endl;

	// Check if everything up to '.' is digit(s)
	if (!is_number(str.substr(start, point - start)))
		return false;
	// std::cerr << "Start to point is digit" << std::endl;
	
	// Check if there are multiple '.'
	if (point != str.find_last_of('.'))
		return false;
	point++;
	//std::cerr << "Single point : " << str.substr(point + 1, fpos - point) << std::endl;

	// Check if everything up to 'f' is digit(s)
	if (!is_number(str.substr(point, fpos - point)))
		return false;
	// std::cerr << "Point to f is digit" << std::endl;

	// Check if there are multiple/invalid 'f' (invalid: not str.last)
	if (fpos != str.find_last_of('f') || fpos != str.length() - 1)
		return false;
	// std::cerr << "Valid/Single float identifier" << std::endl;

	// All checks passed, it's a float!
	return true;
}

bool strisdouble(std::string str)
{
	size_t start = str.find_first_of('-');
	size_t point = str.find_first_of('.');
	
	// Compare to double-specific values
	if (str == "nan" || str == "inf" || str == "-inf")
		return true;

	// Check if there is no point(.)
	if (point == NPOS)
		return false;

	// Check if multiple/invalid minus sign(s) (invalid: not str[0])
	if (start != str.find_last_of('-') || (start != NPOS && start != 0))
		return false;
	start = (start == NPOS) ? 0 : start + 1;

	// Check if everything up to '.' is digit(s)
	if (!is_number(str.substr(start, point - start)))
		return false;
	
	// Check if there are multiple '.'
	if (point != str.find_last_of('.'))
		return false;
	point++;

	// Check if everything up to end is digit(s)
	if (!is_number(str.substr(point)))
		return false;

	// All checks passed, it's a double!
	return true;
}