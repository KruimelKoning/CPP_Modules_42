#include "../header/ClapTrap.hpp"
#include "../header/ScavTrap.hpp"
#include "../header/FragTrap.hpp"

int	main()
{
	std::string	ClapMan = "ClapMan";
	std::string	ScavMan = "ScavMan";
	std::string	FragMan = "FragMan";

	std::cout << "\nConstructing the ClapTraps" << std::endl;
	ClapTrap	_ClapTrap(ClapMan);
	ScavTrap	_ScavTrap(ScavMan);
	FragTrap	_FragTrap(FragMan);

	std::cout << "\nAttacking and repairing" << std::endl;
	_ClapTrap.attack(FragMan);
	_FragTrap.takeDamage(CLAP_ATTACK_DAMAGE);

	_FragTrap.attack(ScavMan);
	_ScavTrap.takeDamage(FRAG_ATTACK_DAMAGE);

	_ScavTrap.beRepaired(20);
	_ScavTrap.attack(ClapMan);
	_ClapTrap.takeDamage(SCAV_ATTACK_DAMAGE);
	_ClapTrap.beRepaired(5);
	_ClapTrap.attack(ScavMan);

	std::cout << "\nGate Keeper Mode" << std::endl;
	_ScavTrap.guardGate();
	_ScavTrap.guardGate();
	_ScavTrap.guardGate();


	std::cout << "\nHigh Fives" << std::endl;
	_FragTrap.highFivesGuys();
	_FragTrap.highFivesGuys();

	std::cout << "\nExhausting FragMan" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		_FragTrap.attack(ScavMan);
		_ScavTrap.takeDamage(FRAG_ATTACK_DAMAGE);
	}
	return 0;
}