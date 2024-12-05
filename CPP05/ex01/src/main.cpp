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

#include "../header/Form.hpp"
#include "../header/Bureaucrat.hpp"

int main()
{
	Bureaucrat	bureaucrat("Yes", 124);
	Form		form("form", 124, 1);

	std::cout << bureaucrat;
	std::cout << form;

	bureaucrat.signForm(form);
	bureaucrat.signForm(form);
	return 0;
}