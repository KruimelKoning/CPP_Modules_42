#pragma once

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string	_Target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm(const std::string _Target);

	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	void	execute(const Bureaucrat& executor) const;

	const std::string&	getTarget() const;
};