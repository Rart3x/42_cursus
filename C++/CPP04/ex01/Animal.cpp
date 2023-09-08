#include "Animal.hpp"

Animal::Animal(void) : type ("Animal"){

	std::cout << "Animal constructor called" << std::endl;

}

Animal::Animal(const Animal &src) : type (src.type){

	if (this != &src){
		*this = src;
		std::cout << "Animal copy constructor called" << std::endl;
	}
}

Animal::~Animal(void){


	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const{

	std::cout << "Animal MakeSound called" << std::endl;
}

Animal&::Animal::operator=(const Animal &src){

	this->type = src.type;

	std::cout << "Copy operator called" << std::endl;
	return *this;
}

Brain* Animal::getBrain(){
	return (NULL);
}

std::string	Animal::getType() const{

	return (this->type);
}