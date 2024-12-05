#include "../header/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _Target(other.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	this->setSigned(other.getSigned());
}

PresidentialPardonForm::PresidentialPardonForm(const std::string _Target) : AForm("Shrubbery", 25, 5), _Target(_Target)
{
	std::cout << "PresidentialPardonForm target constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default deconstructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "PresidentialPardonForm assignment operator overloader called" << std::endl;
	setSigned(other.getSigned());
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& other) const
{
	try
	{
		if (this->getExecuteGrade() < other.getGrade())
			throw GradeTooLow();
		else if (!this->getSigned())
			throw NotSigned();
		else
		{
			std::cout << this->getTarget() << " has been pardoned by Zaphod Beetlebrox" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const std::string&	PresidentialPardonForm::getTarget() const
{
	return this->_Target;
}
