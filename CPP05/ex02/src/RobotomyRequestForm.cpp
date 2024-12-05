#include "../header/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _Target(other.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	this->setSigned(other.getSigned());
}

RobotomyRequestForm::RobotomyRequestForm(const std::string _Target) : AForm("Shrubbery", 72, 45), _Target(_Target)
{
	std::cout << "RobotomyRequestForm target constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default deconstructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm assignment operator overloader called" << std::endl;
	setSigned(other.getSigned());
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& other) const
{
	try
	{
		if (this->getExecuteGrade() < other.getGrade())
			throw GradeTooLow();
		else if (!this->getSigned())
			throw NotSigned();
		else
		{
			std::cout << "Drilling noises..." << std::endl;
			if (rand() % 2)
				std::cout << this->getTarget() << " has been robotimized" << std::endl;
			else
				std::cout << "Robotomy failed" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const std::string&	RobotomyRequestForm::getTarget() const
{
	return this->_Target;
}
