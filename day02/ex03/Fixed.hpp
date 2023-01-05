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
	
	//Assignment
	Fixed& operator = (const Fixed& right);
	//Comparison
	bool operator == (const Fixed& right) const;
	bool operator != (const Fixed& right) const;
	bool operator > (const Fixed& right) const;
	bool operator < (const Fixed& right) const;
	bool operator >= (const Fixed& right) const;
	bool operator <= (const Fixed& right) const;
	//Arithmetic
	Fixed operator + (const Fixed& right) const;
	Fixed operator - (const Fixed& right) const;
	Fixed operator * (const Fixed& right) const;
	Fixed operator / (const Fixed& right) const;
	//Increment
	Fixed& operator ++ ();
	Fixed operator ++ (int);
	Fixed& operator -- ();
	Fixed operator -- (int);

	int getRawBits() const;
	void setRawBits(const int raw);
	float toFloat() const;
	int toInt() const;
	static void setVerbose(bool value);
	static bool isVerbose();

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
private:
	int _value;
	static const int _fractional_bits;
	static const int _bitshift;
	static bool			_verbose;
};
std::ostream& operator << (std::ostream& out, const Fixed& right);

#endif