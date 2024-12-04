/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 14:22:36 by lbartels      #+#    #+#                 */
/*   Updated: 2024/06/19 17:32:11 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

class	Fixed
{
	private:
		int			_Value;
		static int	_fractionalBits;

	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator=(const Fixed& other);

		int		getRawBits();
		void	setRawbits(const int raw);
};