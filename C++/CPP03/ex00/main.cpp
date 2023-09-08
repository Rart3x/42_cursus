#include "ClapTrap.hpp"

int	main(void){

	ClapTrap	keny("Keny"); 
	ClapTrap	dylan("Dylan");

	int	value;

	value = keny.getAttackDamage();
	std::cout << keny.getName() << " have " << value << " damages points" << std::endl;
	
	value = dylan.getHitPoints();
	std::cout << dylan.getName() << " have " << value << " hit points" << std::endl;

	keny.attack("Dylan");
	dylan.takeDamage(keny.getAttackDamage());

	keny.setAttackDamage(4);
	
	keny.attack("Dylan");
	dylan.takeDamage(keny.getAttackDamage());
	value = dylan.getHitPoints();
	std::cout << dylan.getName() << " have " << value << " hit points" << std::endl;
	
	keny.attack("Dylan");
	dylan.takeDamage(keny.getAttackDamage());
	value = dylan.getHitPoints();
	std::cout << dylan.getName() << " have " << value << " hit points" << std::endl;
	
	dylan.beRepaired(2);
	value = dylan.getHitPoints();
	std::cout << dylan.getName() << " have " << value << " hit points" << std::endl;
	
	keny.attack("Dylan");
	dylan.takeDamage(keny.getAttackDamage());
	value = dylan.getHitPoints();
	std::cout << dylan.getName() << " have " << value << " hit points" << std::endl;

	dylan.beRepaired(2);
	value = dylan.getHitPoints();
	std::cout << dylan.getName() << " have " << value << " hit points" << std::endl;
}
