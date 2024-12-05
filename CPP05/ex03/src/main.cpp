/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:36 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/13 13:31:06 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/SchrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/Intern.hpp"

int	main(void)
{

	// Constructors
	std::cout << std::endl;
	std::cout << "CONSTRUCTING:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Intern	intern;
	AForm	*robo_form;
	AForm	*shrub_form;
	AForm	*president_form;
	AForm	*unknown_form;
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "INTERN TESTS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	// Robo:
	robo_form = intern.makeForm("robotomy request", "robo");
	std::cout << *robo_form << "was just created " << std::endl << std::endl;

	// President:
	president_form = intern.makeForm("presidential pardon", "president");
	std::cout << *president_form << " was just created " << std::endl << std::endl;

	// Shrub:
	shrub_form = intern.makeForm("shrubbery creation", "shrub");
	std::cout << *shrub_form << " was just created " << std::endl << std::endl;

	// Unknown:
	try
	{
		unknown_form = intern.makeForm("driving licence", "drive");
		std::cout << *unknown_form << " was just created " << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	delete robo_form;
	delete shrub_form;
	delete president_form;
	return (0);
	//-------------------------------------------------------	
}