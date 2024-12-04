#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define DIAMOND_ATTACK_DAMAGE FRAG_ATTACK_DAMAGE

class	DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;
public:
	// Constructors
	DiamondTrap();
	DiamondTrap(std::string name);

	// Deconstructor
	~DiamondTrap();

	// Operator overloaders
	DiamondTrap&	operator=(const DiamondTrap& other);

	// Member functions
	void	attack(std::string target);
	void	whoAmI();
};
