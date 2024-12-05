#include "../header/Cat.hpp"
#include "../header/Brain.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_Brain = new Brain();
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = other._type;
	this->_Brain = new Brain(*other._Brain);
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor called" << std::endl;
	delete this->_Brain;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	this->_type = other._type;
	// delete this->_Brain;
	this->_Brain = new Brain(*other._Brain);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

std::string	Cat::getIdeas(int32_t index)
{
	return _Brain->ideas[index];
}