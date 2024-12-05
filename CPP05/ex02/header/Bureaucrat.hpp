/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 15:20:21 by lbartels      #+#    #+#                 */
/*   Updated: 2024/10/21 17:27:21 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class	Bureaucrat
{
private:
	const std::string	_Name;
	int		 			_Grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(const std::string _Name, int _Grade);

	~Bureaucrat();

	Bureaucrat&			operator=(const Bureaucrat& other);

	const std::string&	getName() const;
	int					getGrade() const;

	void				incrementGrade();
	void				decrementGrade();

	void				signForm(AForm& form);

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
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);