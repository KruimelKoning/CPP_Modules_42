/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 12:08:06 by lbartels      #+#    #+#                 */
/*   Updated: 2024/06/03 17:18:19 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>

class	Contact
{
	public:
		Contact();
		~Contact();
		Contact(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret);
		void	PrintContacts();
		void	PrintContact();
	protected:
	private:
		std::string	FirstName, LastName, NickName, PhoneNumber, DarkestSecret;
};

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	Add();
		void	Search();
		void	Exit();
	protected:
	private:
		Contact	contacts[8];
		int		index;
};
