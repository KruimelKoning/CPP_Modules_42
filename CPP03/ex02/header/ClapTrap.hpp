#pragma once

#include <iostream>

#define CLAP_ATTACK_DAMAGE 0

class	ClapTrap
{
protected:
	std::string		name;
	unsigned int	HP;
	unsigned int	EP;
	unsigned int	AD;
public:
	// Constructors
	ClapTrap();
	ClapTrap(std::string name);

	// Deconstructor
	~ClapTrap();

	// Operator Overloaders
	ClapTrap&	operator=(const ClapTrap& other);

	// Member functions
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

