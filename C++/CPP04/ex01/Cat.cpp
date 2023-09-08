#include "Cat.hpp"

Cat::Cat(){

	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
	this->brain = new Brain;
}

Cat::Cat(Cat &src) : Animal(src){

	if (this != &src){
		*this = src;
		std::cout << this->type << "copy constructor called" << std::endl;
	}
}

Cat& Cat::operator=(Cat &src){

	if (this != &src) {
		Animal::operator=(src);
		if (this->brain){
			delete this->brain;
		}
		this->brain = new Brain(*src.brain);
	}
	return (*this);
}

Cat::~Cat(){
	
	if (this->brain)
		delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const{

	std::cout << "Miaou !" << std::endl;
}

std::string Cat::getType(){
	
	return (this->type);
}

Brain* Cat::getBrain(){
	return (this->brain);
}