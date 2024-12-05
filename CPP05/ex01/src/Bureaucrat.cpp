/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 16:42:41 by lbartels      #+#    #+#                 */
/*   Updated: 2024/10/21 17:39:03 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _Name(other._Name), _Grade(other._Grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string _Name, int _Grade) : _Name(_Name)
{
	std::cout << "Bureaucrat name/grade constructor called" << std::endl;
	try
	{
		if (_Grade < 1)
			throw GradeTooHigh();
		else if (_Grade > 150)
			throw GradeTooLow();
		else
			this->_Grade = _Grade;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat default deconstructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat assignment overloader called" << std::endl;
	if (this == &other)
		return *this;
	this->_Grade = other.getGrade();
	return *this;
}

const std::string&	Bureaucrat::getName() const
{
	return this->_Name;
}

int	Bureaucrat::getGrade() const
{
	return this->_Grade;
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (this->_Grade <= 1)
			throw GradeTooHigh();
		else
			this->_Grade--;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_Grade >= 150)
			throw GradeTooLow();
		else
			this->_Grade++;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign form because: " << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHigh::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLow::what() const throw()
{
	return "Grade too low";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << '.' << std::endl;
	return os;
}