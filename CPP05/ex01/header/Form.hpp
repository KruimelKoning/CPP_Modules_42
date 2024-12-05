/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 17:53:04 by lbartels      #+#    #+#                 */
/*   Updated: 2024/10/21 18:08:55 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_Name;
	bool				_Signed;
	const int			_signGrade;
	const int			_executeGrade;
public:
	Form();
	Form(const Form& other);
	Form(const std::string _Name, const int _signGrade, const int _executeGrade);
	
	~Form();

	Form&	operator=(const Form& other);

	const std::string	getName() const;
	bool				getSigned() const;
	const int			getSignGrade() const;
	const int			getExecuteGrade() const;

	void				beSigned(Bureaucrat& bureaucrat);

	class	GradeTooHigh : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class	GradeTooLow : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class	AlreadySigned : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Form& form);
