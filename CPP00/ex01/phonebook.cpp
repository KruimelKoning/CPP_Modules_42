/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 12:08:09 by lbartels      #+#    #+#                 */
/*   Updated: 2024/06/03 17:43:19 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact()
{
	
}

Contact::~Contact()
{
	
}

PhoneBook::PhoneBook()
{
	this->index = 0;
	std::cout << "Starting PhoneBook..." << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Quitting PhoneBook..." << std::endl;
}

Contact::Contact(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret)
{
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->NickName = NickName;
	this->PhoneNumber = PhoneNumber;
	this->DarkestSecret = DarkestSecret;
}


void	PhoneBook::Add()
{
	std::string	FirstName, LastName, NickName, PhoneNumber, DarkestSecret;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (true)
	{
		std::cout << "Enter First Name:" << std::endl;
		std::getline(std::cin, FirstName);
		if (FirstName != "")
			break ;
	}
	while (true)
	{
		std::cout << "Enter Last Name:" << std::endl;
		std::getline(std::cin, LastName);
		if (LastName != "")
			break ;
	}
	while (true)
	{
		std::cout << "Enter NickName:" << std::endl;
		std::getline(std::cin, NickName);
		if (NickName != "")
			break ;
	}
	while (true)
	{
		std::cout << "Enter PhoneNumber:" << std::endl;
		std::getline(std::cin, PhoneNumber);
		if (PhoneNumber != "")
			break ;
	}
	while (true)
	{
		std::cout << "Enter Darkest Secret:" << std::endl;
		std::getline(std::cin, DarkestSecret);
		if (DarkestSecret != "")
			break ;
	}
	this->contacts[this->index % 8] = Contact(FirstName, LastName, NickName, PhoneNumber, DarkestSecret);
	this->index++;
}

void	Contact::PrintContacts()
{
	if (this->FirstName.length() <= 9)
	{
		std::string	temp(9 - this->FirstName.length(), ' ');
		std::cout << temp << this->FirstName << " |";
	}
	else
	{
		std::string	temp;
		temp = this->FirstName.substr(0, 9);
		std::cout << temp << ".|";
	}
	if (this->LastName.length() <= 9)
	{
		std::string	temp(9 - this->LastName.length(), ' ');
		std::cout << temp << this->LastName << " |";
	}
	else
	{
		std::string	temp;
		temp = this->LastName.substr(0, 9);
		std::cout << temp << ".|";
	}
	if (this->NickName.length() <= 9)
	{
		std::string	temp(9 - this->NickName.length(), ' ');
		std::cout << temp << this->NickName << " ";
	}
	else
	{
		std::string	temp;
		temp = this->NickName.substr(0, 9);
		std::cout << temp << ".";
	}
	std::cout << std::endl;
}

void	Contact::PrintContact()
{
	std::cout << "First Name:		" << this->FirstName << std::endl;
	std::cout << "Last Name:		"<< this->LastName << std::endl;
	std::cout << "NickName:		"<< this->NickName << std::endl;
	std::cout << "Phonenumber:		"<< this->PhoneNumber << std::endl;
	std::cout << "Darkest Secret:		"<< this->DarkestSecret << std::endl;
}

void	PhoneBook::Search()
{
	std::string	index;

	for (int i = 0; i < 8 && i < this->index; i++)
	{
		std::string temp(8, ' ');
		std::cout << temp << i << " |";
		this->contacts[i].PrintContacts();
	}
	std::cout << "type the index of the contact you want to look up" << std::endl;
	std::cin >> index;
	if ((index.length() != 1) && ((index[0] - 48) <= this->index || index[0] < '0' || index[0] > '7'))
		this->contacts[index[0] - 48].PrintContact();
	else
		std::cout << "this index does not exist" << std::endl;
}
void	PhoneBook::Exit()
{
	this->~PhoneBook();
	exit(EXIT_SUCCESS);
}

int	main()
{
	PhoneBook		_PhoneBook;
	std::string		buffer;

	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!std::cin.eof() || buffer == "EXIT")
	{
		std::cout << "type ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, buffer);
		if (buffer == "ADD")
			_PhoneBook.Add();
		else if (buffer == "SEARCH")
			_PhoneBook.Search();
		else if (buffer == "EXIT")
			_PhoneBook.Exit();
	}
}
