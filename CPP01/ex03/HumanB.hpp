#ifndef HUMANB_HPP
#define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	_Name;
	Weapon*		_Weapon;
public:
	HumanB(std::string _Name);
	~HumanB();
	void	setWeapon(Weapon& _Weapon);
	void	attack();
};

#endif