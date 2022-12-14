#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& input);
	Fixed(const int& input);
	Fixed(const float& input);
	~Fixed();
	
	Fixed& operator = (const Fixed& rhs);

	int getRawBits() const;
	void setRawBits(const int raw);
	float toFloat() const;
	int toInt() const;
	static void setVerbose(bool value);
	static bool isVerbose();
private:
	int _value;
	static const int _fractional_bits;
	static const int _bitshift;
	static bool			_verbose;
};
std::ostream& operator << (std::ostream& out, const Fixed& rhs);

#endif