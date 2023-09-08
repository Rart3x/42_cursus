#include "Cat.hpp"

Cat::Cat(){

	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src){

	if (this != &src){
		*this = src;
		std::cout << this->type << " copy constructor called" << std::endl;
	}
}

Cat&::Cat::operator=(const Cat &src){

	if (this != &src){
		this->type = src.type;
	}
	return (*this);
}

Cat::~Cat(){

	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const{

	std::cout << "Miaou !" << std::endl;
}

std::string Cat::getType(){
	
	return (this->type);
}

