#include "../header/SchrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _Target(other.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	this->setSigned(other.getSigned());
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _Target) : AForm("Shrubbery", 145, 137), _Target(_Target)
{
	std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default deconstructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm assignment operator overloader called" << std::endl;
	setSigned(other.getSigned());
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& other) const
{
	try
	{
		if (this->getExecuteGrade() < other.getGrade())
			throw GradeTooLow();
		else if (!this->getSigned())
			throw NotSigned();
		else
		{
			std::ofstream of(this->_Target + "_shrubbery", std::ios::out);
			of << "binary tree\n";
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const std::string&	ShrubberyCreationForm::getTarget() const
{
	return this->_Target;
}
