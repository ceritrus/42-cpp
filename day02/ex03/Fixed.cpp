#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;
const int Fixed::_bitshift = 1 << Fixed::_fractional_bits;

Fixed::Fixed()
	: _value(0)
{
	#ifdef DEBUG
		std::cout << "Default constructor called" << std::endl;
	#endif
}

Fixed::Fixed(const Fixed& input)
{
	#ifdef DEBUG
		std::cout << "Copy constructor called" << std::endl;
	#endif
	*this = input;
}

Fixed::Fixed(const int& input)
{
	#ifdef DEBUG
		std::cout << "Int constructor called" << std::endl;
	#endif
	_value = input << _fractional_bits;
}

Fixed::Fixed(const float& input)
{
	#ifdef DEBUG
		std::cout << "Float constructor called" << std::endl;
	#endif
	_value = roundf(input * _bitshift);
}

Fixed::~Fixed()
{
	#ifdef DEBUG
		std::cout << "Destructor called" << std::endl;
	#endif
}

Fixed& Fixed::operator=(const Fixed& right)
{
	_value = right.getRawBits();
	return *this;
}

bool Fixed::operator == (const Fixed& right) const
{
	return (_value == right._value);
}

bool Fixed::operator != (const Fixed& right) const
{
	return (_value != right._value);
}

bool Fixed::operator > (const Fixed& right) const
{
	return (_value > right._value);
}

bool Fixed::operator < (const Fixed& right) const
{
	return (_value < right._value);
}

bool Fixed::operator >= (const Fixed& right) const
{
	return (_value >= right._value);
}

bool Fixed::operator <= (const Fixed& right) const
{
	return (_value <= right._value);
}

Fixed Fixed::operator + (const Fixed& right) const
{
	Fixed result;
	result.setRawBits(_value + right._value);
	return result; 
}

Fixed Fixed::operator - (const Fixed& right) const
{
	Fixed result;
	result.setRawBits(_value - right._value);
	return result;
}

Fixed Fixed::operator * (const Fixed& right) const
{
	Fixed result(toFloat() * right.toFloat());
	return result;
}

Fixed Fixed::operator / (const Fixed& right) const
{
	Fixed result(toFloat() / right.toFloat());
	return result;
}

Fixed& Fixed::operator ++ ()
{
	++_value;
	return *this;
}

Fixed Fixed::operator ++ (int)
{
	Fixed temp(*this);
	++_value;
	return temp;
}

Fixed& Fixed::operator -- ()
{
	--_value;
	return *this;
}

Fixed Fixed::operator -- (int)
{
	Fixed temp(*this);
	--_value;
	return temp;
}

int Fixed::getRawBits() const
{
	#ifdef DEBUG
		std::cout << "getRawBits member function called" << std::endl;
	#endif
	return _value;
}

void Fixed::setRawBits(const int raw)
{
	#ifdef DEBUG
		std::cout << "setRawBits member function called" << std::endl;
	#endif
	_value = raw;
}

float Fixed::toFloat() const
{
	return (float)_value / (float)_bitshift;
}

int Fixed::toInt() const
{
	return _value >> _fractional_bits;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& right)
{
	out << right.toFloat();
	return out;
}