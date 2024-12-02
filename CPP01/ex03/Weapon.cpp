#include "Weapon.hpp"

Weapon::Weapon(std::string _Type)
{
	this->_Type = _Type;
}

Weapon::~Weapon()
{

}

void	Weapon::setType(std::string _Type)
{
	this->_Type = _Type;
}

const std::string&	Weapon::getType()
{
	return (this->_Type);
}