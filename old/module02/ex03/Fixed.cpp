#include "Fixed.hpp"

bool Fixed::_verbose = true;
const int Fixed::_fractional_bits = 8;
const int Fixed::_bitshift = 1 << Fixed::_fractional_bits;

Fixed::Fixed()
	: _value(0)
{
	if (Fixed::isVerbose())
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& input)
{
	if (Fixed::isVerbose())
		std::cout << "Copy constructor called" << std::endl;
	*this = input;
}

Fixed::Fixed(const int& input)
{
	if (Fixed::isVerbose())
		std::cout << "Int constructor called" << std::endl;
	_value = input << _fractional_bits;
}

Fixed::Fixed(const float& input)
{
	if (Fixed::isVerbose())
		std::cout << "Float constructor called" << std::endl;
	_value = roundf(input * _bitshift);
}

Fixed::~Fixed()
{
	if (Fixed::isVerbose())
		std::cout << "Destructor called" << std::endl;
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
	if (Fixed::isVerbose())
		std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(const int raw)
{
	if (Fixed::isVerbose())
		std::cout << "setRawBits member function called" << std::endl;
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

void Fixed::setVerbose(bool value)
{
	_verbose = value;
}

bool Fixed::isVerbose()
{
	return _verbose;
}

std::ostream& operator<<(std::ostream& out, const Fixed& right)
{
	out << right.toFloat();
	return out;
}