#include "../header/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	this->_type = other._type;
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "..." << std::endl;
}

std::string&	Animal::getType()
{
	return this->_type;
}