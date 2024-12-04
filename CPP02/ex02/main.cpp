/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 17:15:46 by lbartels      #+#    #+#                 */
/*   Updated: 2024/07/02 18:39:43 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
int main( void ) {
	// Main from subject
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	// Other tests

	// Arithmetic operators
	std::cout << "\nArithmetic operators" << std::endl;
	Fixed	c(Fixed(3.02f) / Fixed(1.50f));
	std::cout << c << std::endl;
	std::cout << c - b << std::endl;
	std::cout << b - a << std::endl;
	std::cout << c * b << std::endl;

	// Min and Max
	std::cout << "\nMin and Max" << std::endl;
	std::cout << "Maximim from b and c: " << Fixed::max( b, c ) << std::endl;
	std::cout << "Minimum from a and c: " << Fixed::min( a, c ) << std::endl;

	// Comparison operators
	std::cout << "\nComparison operators" << std::endl;
	std::cout << ((b != c) ? "b and c are not the same" : "b and c are the same") << std::endl;
	Fixed	d(c);
	std::cout << ((d == c) ? "c and d are the same" : "c and d are not the same") << std::endl;
	std::cout << ((a < b) ? "a is smaller" : "b is smaller") << std::endl;
	std::cout << ((b > c) ? "b is bigger" : "c is bigger") << std::endl;
	std::cout << ((c >= d) ? "c is bigger or the same as d" : "c is not bigger nor the same as d") << std::endl;
	std::cout << ((b <= a) ? "b is smaller or the same as a" : "b is not smaller nor the same as a") << std::endl;

	// In- and decrement
	std::cout << "\nIn- and decrement operators" << std::endl;
	std::cout << ++c << std::endl;
	std::cout << --d << std::endl;
	std::cout << a-- << std::endl;
	std::cout << ++d << std::endl;

	std::cout << "\na: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	return 0;
}