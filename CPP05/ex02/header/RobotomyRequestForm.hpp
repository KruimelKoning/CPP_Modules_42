#pragma once

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string	_Target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm(const std::string _Target);

	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	void	execute(const Bureaucrat& executor) const;

	const std::string&	getTarget() const;
};