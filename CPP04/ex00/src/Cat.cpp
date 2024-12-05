#include "../header/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = other._type;
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	this->_type = other._type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
