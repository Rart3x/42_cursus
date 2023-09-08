#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){

	this->name = "default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << this->name << " ClapTrap is born, congratulations !" << std::endl;
}

ClapTrap::ClapTrap(std::string name){

	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << this->name << " ClapTrap is born, congratulations !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original){

	*this = original;
	std::cout << this->name << " ClapTrap is born by copy constructor, congratulations !" << std::endl;
}

ClapTrap&::ClapTrap::operator=(const ClapTrap &original){

	this->name = original.name;
	this->hitPoints = original.hitPoints;
	this->energyPoints = original.energyPoints;
	this->attackDamage = original.attackDamage;
	std::cout << this->name << " ClapTrap is copied by copy assignment operator called" << std::endl;

	return *this;
}

ClapTrap::~ClapTrap(){

	std::cout << this->name << " ClapTrap is dead." << std::endl;
}

void ClapTrap::attack(const std::string& target){

	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << this->name << " [ClapTrap] Too tired to do anything" << std::endl;
	}
	else
	{
		std::cout << this->name << " [ClapTrap] attacks " << target << " causing " << this->attackDamage << " point of damage" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::beRepaired(unsigned int amount){

	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << this->name << " [ClapTrap] Too tired to do anything" << std::endl;
	}
	else
	{
		std::cout << this->name << " [ClapTrap] self repaired " << amount <<  " amount of hit points." << std::endl;
		this->hitPoints += amount;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount){

	if (this->hitPoints <= amount)
	{
		std::cout << this->name << " [ClapTrap] took " << amount <<  " amount of damages." << std::endl;
		this->hitPoints = 0;
	}
	else
	{
		std::cout << this->name << " [ClapTrap] took " << amount <<  " amount of damages." << std::endl;
		this->hitPoints -= amount;
	}
}

std::string	ClapTrap::getName(){

	return (this->name);
}

void	ClapTrap::setHitPoints(unsigned int amount){

	this->hitPoints = amount;
}

unsigned int ClapTrap::getHitPoints(){

	return (this->hitPoints);
}

void	ClapTrap::setEnergyPoints(unsigned int amount){

	this->energyPoints = amount;
}

unsigned int ClapTrap::getEnergyPoints(){

	return (this->energyPoints);
}

void	ClapTrap::setAttackDamage(unsigned int amount){

	this->attackDamage = amount;
}

unsigned int ClapTrap::getAttackDamage(){

	return (this->attackDamage);
}