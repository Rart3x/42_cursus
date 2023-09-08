#include "HumanB.hpp"

HumanB::HumanB(std::string name){

	this->name = name;
}

HumanB::~HumanB(){

}

void	HumanB::attack(){

	if (this->hWeapon)
	{
		std::cout << this->name << " attacks with their " << this->hWeapon->getType() << std::endl;
	}
	else
		std::cout << this->name << " attacks with their hands "<< std::endl;
}

void	HumanB::setWeapon(Weapon &weapon){
	
	this->hWeapon = &weapon;
}
