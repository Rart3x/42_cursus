#include "WrongCat.hpp"

WrongCat::WrongCat(){

	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src){

	if (this != &src){
		*this = src;
		std::cout << "WrongCat copy constructor called" << std::endl;
	}
}

WrongCat&::WrongCat::operator=(const WrongCat &src){

	if (this != &src){
		this->type = src.type;
	}
	return (*this);
}

WrongCat::~WrongCat(){

	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const{

	std::cout << "Wrong Miaou !" << std::endl;
}

std::string WrongCat::getType(){
	return (this->type);
}