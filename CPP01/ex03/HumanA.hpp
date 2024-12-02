#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string	_Name;
	Weapon&		_Weapon;
public:
	HumanA(std::string _Name, Weapon& _Weapon);
	~HumanA();
	void	attack();
};

#endif