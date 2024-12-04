#include "../header/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_CT")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->HP = FragTrap::HP;
	this->EP = ScavTrap::EP;
	this->AD = FragTrap::AD;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "Default_CT"), _name(name)
{
	std::cout << "DiamondTrap name constructor called for " << this->_name << std::endl;
	this->HP = FragTrap::HP;
	this->EP = ScavTrap::EP;
	this->AD = FragTrap::AD;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap deconstructor called for " << this->name << std::endl;
}

void	DiamondTrap::attack(std::string target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Hello, I am " << this->_name << " I originated from " << ClapTrap::name << std::endl;
}