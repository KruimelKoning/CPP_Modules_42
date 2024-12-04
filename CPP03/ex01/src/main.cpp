#include "../header/ScavTrap.hpp"

int	main()
{
	std::string	ClapMan = "ClapMan";
	std::string	ScavMan = "ScavMan";

	std::cout << "\nConstructing the ClapTraps" << std::endl;
	ClapTrap	_ClapTrap(ClapMan);
	ScavTrap	_ScavTrap(ScavMan);

	std::cout << "\nAttacking and repairing" << std::endl;
	_ClapTrap.attack(ScavMan);
	_ScavTrap.takeDamage(CLAP_ATTACK_DAMAGE);

	_ScavTrap.beRepaired(20);
	_ScavTrap.attack(ClapMan);
	_ClapTrap.takeDamage(SCAV_ATTACK_DAMAGE);
	_ClapTrap.beRepaired(5);
	_ClapTrap.attack(ScavMan);

	std::cout << "\nGate Keeper Mode" << std::endl;
	_ScavTrap.guardGate();
	_ScavTrap.guardGate();
	_ScavTrap.guardGate();

	std::cout << "\n exhausting ScavMan" << std::endl;
	for (int i = 0; i < 50; i++)
	{
		_ScavTrap.attack(ClapMan);
	}
	return 0;
}