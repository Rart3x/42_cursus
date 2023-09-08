#include "Dog.hpp"

Dog::Dog(){

	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
	this->brain = new Brain;
}

Dog::Dog(Dog &src) : Animal(src){

	if (this != &src){
		this->brain = new Brain(*(src.getBrain()));
		this->type = src.getType();
		std::cout << this->type << " copy constructor called" << std::endl;
	}
}

Dog&::Dog::operator=(Dog &src){

	if (this->brain)
		delete (this->brain);
	this->brain = new Brain;
	this->type = src.type;
	
	return (*this);
}

Dog::~Dog(){

	if (this->brain)
		delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {

	std::cout << "Waouf !" << std::endl;
}

Brain* Dog::getBrain(){
	return (this->brain);
}

std::string Dog::getType(){
	return (this->type);
}