#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void){

	ClapTrap	dylan("Dylan");
	ScavTrap	scav("Roger");

	int	value;

	value = scav.getHitPoints();
	std::cout << scav.getName() << " have " << value << " hit points" << std::endl;
	value = scav.getEnergyPoints();
	std::cout << scav.getName() << " have " << value << " energy points" << std::endl;
	value = scav.getAttackDamage();
	std::cout << scav.getName() << " have " << value << " damages points" << std::endl;
	
	value = dylan.getHitPoints();
	std::cout << dylan.getName() << " have " << value << " hit points" << std::endl;

	scav.attack("Dylan");
	dylan.takeDamage(scav.getAttackDamage());

	value = dylan.getHitPoints();
	std::cout << dylan.getName() << " have " << value << " hit points" << std::endl;
	dylan.attack("Jack");


	scav.guardGuate();
}
