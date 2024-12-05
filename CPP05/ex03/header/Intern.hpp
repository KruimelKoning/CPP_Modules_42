#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "SchrubberyCreationForm.hpp"

class	Intern
{
public:
	Intern();
	Intern(const Intern& other);

	~Intern();

	Intern&	operator=(const Intern& other);

	AForm*	makeForm(std::string Form, std::string _Target);

	class FormNotFound : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};