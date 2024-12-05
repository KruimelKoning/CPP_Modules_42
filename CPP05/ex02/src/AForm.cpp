#include "../header/AForm.hpp"
#include "../header/Bureaucrat.hpp"

AForm::AForm() : _Signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm& other) : _Name(other._Name), _Signed(other._Signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::AForm(std::string _Name, const int _signGrade, const int _executeGrade) : _Name(_Name), _Signed(false), _signGrade(_signGrade), _executeGrade(_executeGrade)
{
	std::cout << "AForm parameter constructor called" << std::endl;
	
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

AForm::~AForm()
{
	std::cout << "AForm default deconstructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm& other)
{
	std::cout << "AForm assignment operator overloader called" << std::endl;
	this->_Signed = other._Signed;
	return *this;
}

const std::string	AForm::getName() const
{
	return this->_Name;
}

bool	AForm::getSigned() const
{
	return this->_Signed;
}

const int	AForm::getSignGrade() const
{
	return this->_signGrade;
}
const int	AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

void	AForm::setSigned(bool _Signed)
{
	this->_Signed = _Signed;
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooLow();
	else if (this->getSigned())
		throw AlreadySigned();
	else
		this->_Signed = true;
}

const char* AForm::GradeTooHigh::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLow::what() const throw()
{
	return "Grade too low";
}

const char* AForm::AlreadySigned::what() const throw()
{
	return "Form already signed";
}

const char* AForm::NotSigned::what() const throw()
{
	return "Form not signed";
}

std::ostream&	operator<<(std::ostream& os, const AForm& AForm)
{
	os << "AForm: " << AForm.getName() << std::endl \
		<< "Signed: " << (AForm.getSigned() ? "True" : "False") << std::endl \
		<< "Sign Grade: " << AForm.getSignGrade() << std::endl \
		<< "Execute Grade: " << AForm.getExecuteGrade() << std::endl;
	return os;
}
