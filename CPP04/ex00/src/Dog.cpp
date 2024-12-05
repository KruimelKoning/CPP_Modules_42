#include "../header/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = other._type;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	this->_type = other._type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
