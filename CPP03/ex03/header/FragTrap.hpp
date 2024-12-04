#pragma once

#include "ClapTrap.hpp"
#include <iostream>

#define FRAG_ATTACK_DAMAGE 30

class	FragTrap : virtual public ClapTrap
{
private:
	
public:
	// Constructors
	FragTrap();
	FragTrap(std::string name);

	// Deconstructor
	virtual ~FragTrap();

	// Operator overloaders
	FragTrap&	operator=(const FragTrap& other);

	// Member functions
	void	highFivesGuys();
};
