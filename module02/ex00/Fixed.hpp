#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& origin);
	~Fixed();
	
	Fixed& operator = (const Fixed& rhs);

	int getRawBits() const;
	void setRawBits(const int raw);
	static void setVerbose(bool value);
private:
	int _value;
	static const int _fractional_bits = 8;
	static bool			_verbose;
};

#endif