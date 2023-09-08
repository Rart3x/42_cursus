#include "Dog.hpp"

Dog::Dog(){

	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src){

	if (this != &src){
		*this = src;
		std::cout << this->type << " copy constructor called" << std::endl;
	}
}

Dog&::Dog::operator=(const Dog &src){

	if (this != &src){
		this->type = src.type;
	}
	return (*this);
}

Dog::~Dog(){

	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {

	std::cout << "Waouf !" << std::endl;
}

std::string Dog::getType(){
	return (this->type);
}