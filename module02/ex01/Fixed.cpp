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

Fixed& Fixed::operator=(const Fixed& rhs)
{
	_value = rhs.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& rhs)
{
	out << rhs.toFloat();
	return out;
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

void Fixed::setVerbose(bool value)
{
	_verbose = value;
}

bool Fixed::isVerbose()
{
	return _verbose;
}