#include "../header/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->HP = 100;
	this->EP = 100;
	this->AD = 30;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "FragTrap name constructor called for " << this->name << std::endl;
	this->HP = 100;
	this->EP = 100;
	this->AD = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap deconstructor called for " << this->name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	this->name = other.name;
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	return *this;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " wants to high five!" << std::endl;
}