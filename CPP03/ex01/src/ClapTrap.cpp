#include "../header/ClapTrap.hpp"

ClapTrap::ClapTrap() : HP(10), EP(10), AD(0)
{
	std::cout << "ClapTrap default constructor called"<< std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap deconstructor called for " << this->name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), HP(10), EP(10), AD(0)
{
	std::cout << "ClapTrap name constructor called for " << this->name << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Assignment operator called" << std::endl;
	this->name = other.name;
	this->HP = other.HP;
	this->HP = other.EP;
	this->HP = other.AD;
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << this->name;
	if (this->EP && this->HP)
	{
		std::cout << " attacks " << target << " causing " << this->AD << " damage" << std::endl;
		this->EP--;
	}
	else
	{
		std::cout << " can't attack because it has no " << \
			(!this->EP ? "Energy points" : "Hit points") << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->name;
	if (!this->HP)
	{
		std::cout << " is already destroyed" << std::endl;
	}
	else
	{
		std::cout << " takes " << amount << " damage";
		if (this->HP < amount)
			std::cout << " and is destroyed";
		this->HP = this->HP <= amount ? 0 : this->HP - amount;
		std::cout << "\nHit Points: " << this->HP << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->name;
	if (this->EP && this->HP)
	{
		std::cout << " repairs " << amount << " of Hit Points";
		this->HP += amount;
	}
	else
	{
		std::cout << " can't repair because it has no " << \
			(!this->EP ? "Energy Points" : "Hit Points");
	}
	std::cout << "\nHit Points: " << this->HP << std::endl;
}