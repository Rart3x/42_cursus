#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	this->ClapTrap::name = name + "clap_name";
	std::cout << this->name << " [DiamondTrap] - is born" << std::endl;
};


DiamondTrap::DiamondTrap(std::string name){

	this->name = name;
	this->ClapTrap::name = name + "_clap_name";

	FragTrap::hitPoints = 100;
	ScavTrap::energyPoints = 100;
	FragTrap::attackDamage = 30;
	std::cout << this->name << " [DiamondTrap] - is born" << std::endl;
} 

DiamondTrap&::DiamondTrap::operator=(const DiamondTrap &original){

	this->name = original.name;
	this->hitPoints = original.hitPoints;
	this->energyPoints = original.energyPoints;
	this->attackDamage = original.attackDamage;
	std::cout << this->name << " DiamondTrap is copied by copy assignment operator called" << std::endl;

	return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original) : ClapTrap(original), FragTrap(original), ScavTrap(original){

	*this = original;
	std::cout << this->name << "DiamondTrap is born by copy constructor, congratulations !" << std::endl;
}

DiamondTrap::~DiamondTrap(){

	std::cout << "[DiamondTrap] - " << this->name << " has been destroyed" << std::endl;
}

void	DiamondTrap::whoAmI(){
	std::cout << "I am a [DiamondTrap], my name is " << this->name << " and my [ClapTrap] name is " << ClapTrap::getName() << std::endl;
}

std::string	DiamondTrap::getName(){
	std::cout << "Diamond Trap getName()" << std::endl;
	return (this->name);
}
