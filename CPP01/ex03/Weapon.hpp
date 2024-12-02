#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class	Weapon
{
	private:
		std::string	_Type;
	public:
		Weapon(std::string _Type);
		~Weapon();
		void		setType(std::string _Type);
		const std::string&	getType();
};

#endif