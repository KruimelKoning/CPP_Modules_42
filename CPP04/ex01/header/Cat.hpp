#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
private:
	Brain*	_Brain;

public:
	Cat();
	Cat(const Cat& other);

	~Cat();

	Cat&	operator=(const Cat& other);

	void		makeSound() const;
	std::string	getIdeas(int32_t index);
};