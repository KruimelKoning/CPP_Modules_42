#include "../header/Form.hpp"
#include "../header/Bureaucrat.hpp"

Form::Form() : _Signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form& other) : _Name(other._Name), _Signed(other._Signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string _Name, const int _signGrade, const int _executeGrade) : _Name(_Name), _Signed(false), _signGrade(_signGrade), _executeGrade(_executeGrade)
{
	std::cout << "Form parameter constructor called" << std::endl;
	
	try
	{
		if (_signGrade < 1 || _executeGrade < 1)
			throw GradeTooHigh();
		else if (_signGrade > 150 || _executeGrade > 150)
			throw GradeTooLow();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::~Form()
{
	std::cout << "Form default deconstructor called" << std::endl;
}

Form&	Form::operator=(const Form& other)
{
	std::cout << "Form assignment operator overloader called" << std::endl;
	this->_Signed = other._Signed;
	return *this;
}

const std::string	Form::getName() const
{
	return this->_Name;
}

bool	Form::getSigned() const
{
	return this->_Signed;
}

const int	Form::getSignGrade() const
{
	return this->_signGrade;
}
const int	Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooLow();
	else if (this->getSigned())
		throw AlreadySigned();
	else
		this->_Signed = true;
}

const char* Form::GradeTooHigh::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLow::what() const throw()
{
	return "Grade too low";
}

const char* Form::AlreadySigned::what() const throw()
{
	return "Form already signed";
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName() << std::endl \
		<< "Signed " << (form.getSigned() ? "True" : "False") << std::endl \
		<< "Sign Grade: " << form.getSignGrade() << std::endl \
		<< "Execute Grade: " << form.getExecuteGrade() << std::endl;
	return os;
}
