#include "HumanA.hpp"

HumanA::HumanA(std::string _Name, Weapon& _Weapon) : _Name(_Name), _Weapon(_Weapon)
{
	
}

HumanA::~HumanA()
{
	
}


void	HumanA::attack()
{
	std::cout << this->_Name << " attacks with their " \
		<< this->_Weapon.getType() << std::endl;
}