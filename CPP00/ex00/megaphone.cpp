/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 11:29:42 by lbartels      #+#    #+#                 */
/*   Updated: 2024/05/29 12:05:28 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	for (int i = 1 ; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			argv[i][j] = toupper(argv[i][j]);
		}
		std::cout << argv[i];
	}
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}
