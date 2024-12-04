#include "../header/DiamondTrap.hpp"

int	main()
{
	DiamondTrap	_DiamondTrap("JOHN_");
	DiamondTrap	_DiamondTrap2;

	_DiamondTrap.whoAmI();
	_DiamondTrap2.whoAmI();
	_DiamondTrap2.attack("JOHN_");
	_DiamondTrap.takeDamage(DIAMOND_ATTACK_DAMAGE);
	return 0;
}