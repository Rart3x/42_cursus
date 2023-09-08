#include "Fixed.hpp"

Fixed::Fixed(){

	std::cout << "Default constructor called" << std::endl;
	this->nb = 0;
}

Fixed::Fixed(const Fixed &original){

	std::cout << "Copy contructor called" << std::endl;
	this->setRawBits(original.getRawBits());
}

Fixed&::Fixed::operator=(const Fixed &original){

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original)
		this->nb = original.getRawBits();
	return *this;
}

Fixed::~Fixed(){

	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void)const{

	std::cout << "getRawbBits member function called" << std::endl;
	return (this->nb);
}

void	Fixed::setRawBits(int const raw){

	this->nb = raw;
}
