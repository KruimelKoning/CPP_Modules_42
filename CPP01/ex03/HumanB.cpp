#include "HumanB.hpp"

HumanB::HumanB(std::string _Name) : _Name(_Name)
{
	this->_Weapon = NULL;
}

HumanB::~HumanB()
{
	
}


void	HumanB::setWeapon(Weapon& _Weapon)
{
	this->_Weapon = &_Weapon;
}

void	HumanB::attack()
{
	if (this->_Weapon)
	{
		std::cout << this->_Name << " attacks with their " \
			<< (*this->_Weapon).getType() << std::endl;
	}
	else
	{
		std::cout << this->_Name << " tries to attack, but has no weapon" << std::endl;
	}
}