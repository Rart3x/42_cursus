#include "Fixed.hpp"

/*------------------constructor---------------*/

Fixed::Fixed(){

	this->nb = 0;
}

Fixed::Fixed(const Fixed &original){

	this->setRawBits(original.getRawBits());
}

Fixed::Fixed(const int n) : nb (n << rawBits){

}

Fixed::Fixed(const float n) : nb (roundf(n * (1 << rawBits))){

}

/*------------------destructor---------------*/

Fixed::~Fixed(){

}


/*------------------rawBits_f---------------*/

int		Fixed::getRawBits(void)const{

	return (this->nb);
}

void	Fixed::setRawBits(int const raw){

	this->nb = raw;
}

/*------------------to_f---------------*/

float   Fixed::toFloat(void)const{

	return static_cast<float>(this->getRawBits()) / (1 << rawBits);
}

int     Fixed::toInt(void)const{

	return (this->nb >> rawBits);
}

/*------------------overloaded_f---------------*/

Fixed&::Fixed::operator=(const Fixed &original){

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original)
		this->nb = original.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &out, Fixed const &i){

    out << i.toFloat();
    return (out);
}

bool    Fixed::operator>(const Fixed &rhs)const{
    return this->getRawBits() > rhs.getRawBits();
}

bool    Fixed::operator<(const Fixed &rhs)const{
    return this->getRawBits() < rhs.getRawBits();
}

bool    Fixed::operator>=(const Fixed &rhs)const{
    return this->getRawBits() >= rhs.getRawBits();
}

bool   Fixed::operator<=(const Fixed &rhs)const{
    return this->getRawBits() <= rhs.getRawBits();
}

bool  Fixed::operator==(const Fixed &rhs)const{
    return this->getRawBits() == rhs.getRawBits();
}

bool    Fixed::operator!=(const Fixed &rhs)const{
    return this->getRawBits() != rhs.getRawBits();
}

/*------------------Arithmetic_o------------------*/

Fixed   Fixed::operator+(const Fixed &rhs)const{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-(const Fixed &rhs)const{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*(const Fixed &rhs)const{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/(const Fixed &rhs)const{
    return Fixed(this->toFloat() / rhs.toFloat());
}

/*------------------Increment-Decrement_o------------------*/

Fixed&   Fixed::operator++(void){

    ++this->nb;

    return (*this);
}

Fixed   Fixed::operator++(int){

    Fixed tmp(*this);

    tmp.nb = this->nb++;
    
	return (tmp);
}

Fixed& Fixed::operator--(void){
	
	--this->nb;
    
	return (*this);
}

Fixed Fixed::operator--(int){

	Fixed tmp(*this);
	
	tmp.nb = this->nb--;
    
	return (tmp);
}

/*-----------------------Max-Min_f----------------------*/

Fixed& Fixed::min(Fixed &a, Fixed &b){

	if (a.getRawBits() < b.getRawBits()){
		return (a);
	}
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b){

	if (a.getRawBits() < b.getRawBits()){
		return (a);
	}
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b){

	if (a.getRawBits() > b.getRawBits()){
		return (a);
	}
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b){

	if (a.getRawBits() > b.getRawBits()){
		return (a);
	}
	return (b);
}
