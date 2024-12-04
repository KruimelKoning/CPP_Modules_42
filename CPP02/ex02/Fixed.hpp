/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 14:22:36 by lbartels      #+#    #+#                 */
/*   Updated: 2024/07/02 18:29:27 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Fixed
{
	private:
		int			_Value;
		static int	_fractionalBits;

	public:
		// Constructors
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int n);
		Fixed(const float n);

		// Deconstructor
		~Fixed();

		// Copy operator
		Fixed&	operator=(const Fixed& other);

		// Member function
		int		getRawBits() const;
		void	setRawbits(const int raw);

		float	toFloat() const;
		int		toInt() const;

		bool	operator<(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		float	operator+(const Fixed& other) const;
		float	operator-(const Fixed& other) const;
		float	operator*(const Fixed& other) const;
		float	operator/(const Fixed& other) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& other);