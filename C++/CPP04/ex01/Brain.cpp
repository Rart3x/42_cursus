#include "Brain.hpp"

Brain::Brain(){
	
	for(int i = 0; i < 100; i++)
		this->ideas[i] = "Hello there";
	std::cout << "Brain constructor has been called" << std::endl;
}

Brain::Brain(Brain &src){

	if (this != &src){
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i] + " copied";
		std::cout << "Brain copy constructor called" << std::endl;
	}
}

Brain Brain::operator=(Brain &src){

	if (this != &src){
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i] + " copied";
	}
	return *(this);
}

Brain::~Brain(){

	std::cout << "Brain destructor has been called" << std::endl;
}

std::string* Brain::getIdeas(){

	return (this->ideas);
}

void Brain::printIdeas(int nbr){

	if (nbr >= 0 && nbr <= 100){
		for (int i = 0; i < nbr; i++)
			std::cout << this->ideas[i] << std::endl;
	}
}