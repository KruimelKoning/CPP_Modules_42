#pragma once

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string	_Target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm(const std::string _Target);

	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	void	execute(const Bureaucrat& executor) const;

	const std::string&	getTarget() const;
};