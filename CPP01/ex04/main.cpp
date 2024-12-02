#include "Replace.hpp"
#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4 || !argv[1][0] || !argv[2][0])
		return (std::cerr << "Invalid args" << std::endl, 1);

	std::fstream file(argv[1], std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		return 1;
	}
	file.seekg(0, std::ios::beg);
	std::string	line;
	while (std::getline(file, line))
	{
		if (line == "test")
			std::cout << line << std::endl;
	}
	file.close();
}