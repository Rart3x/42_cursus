#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type ("WrongAnimal"){

	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src){

	if (this != &src){
		*this = src;
		std::cout << "WrongAnimal copy constructor called" << std::endl;
	}
}

WrongAnimal&::WrongAnimal::operator=(const WrongAnimal &src){

	if (this != &src){
		this->type = src.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(void){

	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const{

	std::cout << "WrongAnimal MakeSound called" << std::endl;

}

std::string	WrongAnimal::getType() const{

	return (this->type);
}
