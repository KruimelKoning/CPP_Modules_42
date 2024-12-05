#pragma once

#include <iostream>

class WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);

	virtual ~WrongAnimal();

	WrongAnimal&	operator=(const WrongAnimal& other);

	void	makeSound() const;
	std::string&	getType();
};