#include "../header/Dog.hpp"
#include "../header/Brain.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_Brain = new Brain();
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = other._type;
	this->_Brain = new Brain(*other._Brain);
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called" << std::endl;
	delete this->_Brain;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	this->_type = other._type;
	delete this->_Brain;
	this->_Brain = new Brain(*other._Brain);
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

std::string	Dog::getIdeas(int32_t index)
{
	return _Brain->ideas[index];
}