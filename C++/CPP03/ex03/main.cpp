#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void){

	DiamondTrap keny("Keny");

	keny.whoAmI();
	std::cout << keny.getName() << " have "  << keny.getHitPoints() << " hit points and amount damage of " << keny.getAttackDamage() << " and amount of energy points of" << keny.getEnergyPoints()  << std::endl; 
	keny.attack("Feldup");
	keny.takeDamage(5);
	keny.beRepaired(5);
}
