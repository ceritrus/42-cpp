#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

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