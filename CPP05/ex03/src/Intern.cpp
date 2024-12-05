#include "../header/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern::~Intern()
{
	std::cout << "Intern default deconstructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern assignment operotar called, but nothing to copy" << std::endl;

	return *this;
}

AForm*	newShrubbery(const std::string _Target)
{
	return new ShrubberyCreationForm(_Target);
}

AForm*	newRobotomy(const std::string _Target)
{
	return new RobotomyRequestForm(_Target);
}

AForm*	newPresidential(const std::string _Target)
{
	return new PresidentialPardonForm(_Target);
}

AForm*	Intern::makeForm(std::string Form, std::string _Target)
{
	const std::string	formStr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*f[3])(std::string) = {newShrubbery, newRobotomy, newPresidential};


	for (int i = 0; i < 3; i++)
	{
		if (Form == formStr[i])
			return f[i](_Target);
	}
	throw FormNotFound();
}

const char* Intern::FormNotFound::what() const throw()
{
	return ("Form Not Found");
}