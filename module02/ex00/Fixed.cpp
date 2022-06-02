#include "Fixed.hpp"

bool Fixed::_verbose = true;
const int Fixed::_fractional_bits = 8;

Fixed::Fixed()
	: _value(0)
{
	if (_verbose)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& input)
{
	if (_verbose)
		std::cout << "Copy constructor called" << std::endl;
	*this = input;
}

Fixed::~Fixed()
{
	if (_verbose)
		std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	if (_verbose)
		std::cout << "Copy assignment operator called" << std::endl;
	_value = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	if (_verbose)
		std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(const int raw)
{
	if (_verbose)
		std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

void Fixed::setVerbose(bool value)
{
	_verbose = value;
}