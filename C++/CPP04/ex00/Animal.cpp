#include "Animal.hpp"

Animal::Animal(void) : type ("Animal"){

	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string _type) : type(_type){

	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src) : type (src.type){

	if (this != &src){
		*this = src;
		std::cout << this->type << " copy constructor called" << std::endl;
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

std::string	Animal::getType() const{

	return (this->type);
}
