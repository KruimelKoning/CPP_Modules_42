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

#include "../header/Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat("Yes", 151);
	Bureaucrat bureaucrat2("Nope", 5);

	std::cout << bureaucrat2;
	for (int i = 0; i < 5; i++)
	{
		bureaucrat2.incrementGrade();
	}
	bureaucrat = bureaucrat2;
	std::cout << bureaucrat;
	return 0;
}