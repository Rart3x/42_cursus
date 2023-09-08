#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& hWeapon) : hWeapon(hWeapon){

	this->name = name;
	this->hWeapon = hWeapon;
}

HumanA::~HumanA(){

}

void	HumanA::attack(){

	std::cout << this->name << " attacks with their " << this->hWeapon.getType() << std::endl;

}

void	HumanA::setWeapon(Weapon &weapon){
	
	this->hWeapon = weapon;
}
