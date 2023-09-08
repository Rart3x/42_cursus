#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){

	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->name = name;
	std::cout << this->name << " ScavTrap is born" << std::endl;
} 

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original){

	*this = original;
	std::cout << this->name << "ScavTrap is born by copy constructor, congratulations !" << std::endl;
}

ScavTrap::~ScavTrap(){

	std::cout << "Scavtrap " << this->name << " has been destroyed" << std::endl;
}

ScavTrap&::ScavTrap::operator=(const ScavTrap &original){

	this->name = original.name;
	this->hitPoints = original.hitPoints;
	this->energyPoints = original.energyPoints;
	this->attackDamage = original.attackDamage;
	std::cout << this->name << "ScavTrap is copied by copy assignment operator called" << std::endl;

	return *this;
}

void ScavTrap::attack(const std::string& target){

	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << this->name << " [ScavTrap] Too tired to do anything" << std::endl;
	}
	else
	{
		std::cout << this->name << " [ScavTrap] attacks " << target << " causing " << this->attackDamage << " point of damage" << std::endl;
		this->energyPoints--;
	}
}

void	ScavTrap::guardGuate(){

	std::cout << this->name << " [ScavTrap] enter in guard mode" << std::endl;
}
