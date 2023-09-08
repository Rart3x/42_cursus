#include "Zombie.hpp"

Zombie::Zombie(void){
}

Zombie::Zombie(std::string name){

	this->name = name;
}

Zombie::~Zombie(void){
	
	std::cout << getName() << " the zombie has been destroyed :(" << std::endl;
}

void	Zombie::announce(void) const {

	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(){

	return (this->name);
}

void	Zombie::setName(std::string &name){

	this->name = name;
}
