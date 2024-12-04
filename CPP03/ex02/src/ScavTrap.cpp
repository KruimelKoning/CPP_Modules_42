#include "../header/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _guardGateMode(false)
{
	this->HP = 100;
	this->EP = 50;
	this->AD = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name), _guardGateMode(false)
{
	this->HP = 100;
	this->EP = 50;
	this->AD = 20;
	std::cout << "ScavTrap name constructor called for " << this->name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap deconstructor called for " << this->name << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	this->name = other.name;
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	return *this;
}

void	ScavTrap::attack(std::string& target)
{
	std::cout << "ScavTrap " << this->name;
	if (this->EP && this->HP)
	{
		std::cout << " attacks " << target << " causing " \
			<< this->AD << " points of damage" << std::endl;
		this->EP--;
	}
	else
	{
		std::cout << " wants to attack, but has no " \
			<< (!this->EP || !this->HP ? "Energy Points" : "Points left") << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is " << \
		(!this->_guardGateMode ?  "in Gate Keeper Mode" : "not in Gate Keeper Mode anymore") << std::endl;
	this->_guardGateMode = !this->_guardGateMode;
}