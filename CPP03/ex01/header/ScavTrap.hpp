#pragma once

#include "ClapTrap.hpp"
#include <iostream>

#define SCAV_ATTACK_DAMAGE 20

class	ScavTrap : public ClapTrap
{
private:
	bool	_guardGateMode;

public:
	// Constructors
	ScavTrap();
	ScavTrap(std::string _name);

	// Deconstructor
	~ScavTrap();

	// Operator overloaders
	ScavTrap&	operator=(const ScavTrap& other);

	// Member function
	void	guardGate();
	void	attack(std::string& target);
};