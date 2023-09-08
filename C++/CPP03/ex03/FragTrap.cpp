#include "FragTrap.hpp"

FragTrap::FragTrap(){

	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << this->name << " FragTrap is born" << std::endl;
} 

FragTrap::FragTrap(std::string name){

	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << this->name << " FragTrap is born" << std::endl;
} 

FragTrap::FragTrap(const FragTrap &original) : ClapTrap(original){

	*this = original;
	std::cout << this->name << "FragTrap is born by copy constructor, congratulations !" << std::endl;
}

FragTrap::~FragTrap(){

	std::cout << "Fragtrap " << this->name << " has been destroyed" << std::endl;
}

FragTrap&::FragTrap::operator=(const FragTrap &original){

	this->name = original.name;
	this->hitPoints = original.hitPoints;
	this->energyPoints = original.energyPoints;
	this->attackDamage = original.attackDamage;
	std::cout << this->name << " FragTrap is copied by copy assignment operator called" << std::endl;

	return *this;
}

void	FragTrap::highFivesGuys(){

	std::cout << this->getName() << " [FraTrap] Lets do some highfives" << std::endl;
}
