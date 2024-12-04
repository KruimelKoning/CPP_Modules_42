/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 14:32:47 by lbartels      #+#    #+#                 */
/*   Updated: 2024/07/02 18:34:27 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath>

int	Fixed::_fractionalBits = 8;


// Constructors
Fixed::Fixed(): _Value(0)
{
	// std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int constructor called" << std::endl;
	_Value = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
	// std::cout << "Float constructor called" << std::endl;
	_Value = (int)roundf(n * (1 << _fractionalBits));
}

// Deconstrucor
Fixed::~Fixed()
{
	// std::cout << "Deconstructor called" << std::endl;
}

// Copy operator
Fixed&	Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_Value = other._Value;
	}
	return *this;
}

// Member functions
int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_Value;
}

void	Fixed::setRawbits(const int raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_Value = raw;
}

float	Fixed::toFloat() const
{
	return (float)_Value / (float)(1 << _fractionalBits);
}

int	Fixed::toInt() const
{
	return (int)_Value >> _fractionalBits;
}

// Operator overloaders
std::ostream&	operator<<(std::ostream& ostream, const Fixed& fixed)
{
	ostream << fixed.toFloat();

	return ostream;
}

bool	Fixed::operator<(const Fixed& other) const
{
	return this->toFloat() < other.toFloat();
}

bool	Fixed::operator>(const Fixed& other) const
{
	return this->toFloat() > other.toFloat();
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return this->toFloat() <= other.toFloat();
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return this->toFloat() >= other.toFloat();
}

bool	Fixed::operator==(const Fixed& other) const
{
	return this->toFloat() == other.toFloat();
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return this->toFloat() != other.toFloat();
}

float	Fixed::operator+(const Fixed& other) const
{
	return this->toFloat() + other.toFloat();
}

float	Fixed::operator-(const Fixed& other) const
{
	return this->toFloat() - other.toFloat();
}

float	Fixed::operator*(const Fixed& other) const
{
	return this->toFloat() * other.toFloat();
}

float	Fixed::operator/(const Fixed& other) const
{
	return this->toFloat() / other.toFloat();
}

Fixed&	Fixed::operator++()
{
	this->_Value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	Temp = *this;
	
	++this->_Value;
	return (Temp);
}

Fixed&	Fixed::operator--()
{
	this->_Value--;
	return (*this);
}


Fixed	Fixed::operator--(int)
{
	Fixed	Temp = *this;
	--this->_Value;
	return (Temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}