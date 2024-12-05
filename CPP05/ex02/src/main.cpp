/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 17:36:49 by lbartels      #+#    #+#                 */
/*   Updated: 2024/10/21 17:42:12 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AForm.hpp"
#include "../header/Bureaucrat.hpp"
#include "../header/SchrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"


int main()
{
	Bureaucrat bureaucrat("Yes", 1);
	ShrubberyCreationForm		form2("form");
	ShrubberyCreationForm		form;

	 RobotomyRequestForm	Robot("no");
	 RobotomyRequestForm	Pardon("yes");

	Pardon.execute(bureaucrat);
	bureaucrat.signForm(Pardon);
	bureaucrat.signForm(Robot);
	Robot.execute(bureaucrat);
	Pardon.execute(bureaucrat);

	form = form2;
	std::cout << bureaucrat;
	std::cout << form;

	bureaucrat.signForm(form);
	bureaucrat.signForm(form);

	form.execute(bureaucrat);
	return 0;
}