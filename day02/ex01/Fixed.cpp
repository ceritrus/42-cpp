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

Fixed& Fixed::operator=(const Fixed& rhs)
{
	#ifdef DEBUG
		std::cout << "Copy assignment operator called" << std::endl;
	#endif
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