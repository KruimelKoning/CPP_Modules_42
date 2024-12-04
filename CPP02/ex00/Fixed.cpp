/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 14:32:47 by lbartels      #+#    #+#                 */
/*   Updated: 2024/06/19 17:18:26 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int	Fixed::_fractionalBits = 8;

Fixed::Fixed(): _Value(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_Value = other._Value;
	}
	return *this;
}

int	Fixed::getRawBits()
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_Value;
}

void	Fixed::setRawbits(const int raw)
{
	
	std::cout << "setRawBits member function called" << std::endl;
	this->_Value = raw;
}