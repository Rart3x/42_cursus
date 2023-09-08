#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void){

	ClapTrap	dylan("Dylan");
	FragTrap	frag("Roger");

	int	value;

	value = frag.getHitPoints();
	std::cout << frag.getName() << " have " << value << " hit points" << std::endl;
	value = frag.getEnergyPoints();
	std::cout << frag.getName() << " have " << value << " energy points" << std::endl;
	value = frag.getAttackDamage();
	std::cout << frag.getName() << " have " << value << " damages points" << std::endl;
	
	value = dylan.getHitPoints();
	std::cout << dylan.getName() << " have " << value << " hit points" << std::endl;

	frag.attack("Dylan");
	dylan.takeDamage(frag.getAttackDamage());

	value = dylan.getHitPoints();
	std::cout << dylan.getName() << " have " << value << " hit points" << std::endl;

	frag.highFivesGuys();
}
