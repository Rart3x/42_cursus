#include "Fixed.hpp"

Fixed::Fixed(){

	std::cout << "Default constructor called" << std::endl;
	this->nb = 0;
}

Fixed::Fixed(const Fixed &original){

	std::cout << "Copy contructor called" << std::endl;
	this->setRawBits(original.getRawBits());
}

Fixed::Fixed(const int n) : nb (n << rawBits){

	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : nb (roundf(n * (1 << rawBits))){

	std::cout << "Float constructor called" << std::endl;
}

Fixed&::Fixed::operator=(const Fixed &original){

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original)
		this->nb = original.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream &out, Fixed const &i){

    out << i.toFloat();
    return (out);
}

Fixed::~Fixed(){

	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void)const{

	return (this->nb);
}

void	Fixed::setRawBits(int const raw){

	this->nb = raw;
}

float   Fixed::toFloat(void)const{

	return static_cast<float>(this->getRawBits()) / (1 << rawBits);
}

int     Fixed::toInt(void)const{

	return this->nb >> rawBits;
}
