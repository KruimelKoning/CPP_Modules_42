#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
private:
	Brain*	_Brain;

public:
	Dog();
	Dog(const Dog& other);

	~Dog();

	Dog&	operator=(const Dog& other);

	void		makeSound() const;
	std::string	getIdeas(int32_t index);
};