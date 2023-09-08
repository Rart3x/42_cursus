#include "Fixed.hpp"

int main(void){

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout  << "Max_f : " << Fixed::max(a, b) << std::endl;
	std::cout << "Min_f : " << Fixed::min(a, b) << std::endl;

	if ((a >= b) == false)
		std::cout << "a >= b : FALSE" << std::endl;
	if ((a <= b) == true)
		std::cout << "a <= b : TRUE" << std::endl;
	if ((a == b) == false)
		std::cout << "a == b : FALSE" << std::endl;
	if ((a > b) == false)
		std::cout << "a > b : FALSE" << std::endl;
	if ((a < b) == true)
		std::cout << "a < b : TRUE" << std::endl;

	std::cout << "a : "<< a << std::endl;
	a--;
	std::cout << "a : "<< a << std::endl;
	a++;
	std::cout << "a : "<< a << std::endl;
	--a;
	std::cout << "a : "<< a << std::endl;
	++a;
	std::cout << "a : "<< a << std::endl;

	a = b;
	a = a / b;
	std::cout << "a / b : "<< a << std::endl;
	a = a * b;
	std::cout << "a * b : "<< a << std::endl;
	a = a + 4;
	std::cout << "a + 4 : "<< a << std::endl;
	a = a - 4;
	std::cout << "a - 4 : "<< a << std::endl;
	if ((a == b) == true)
		std::cout << "a == b : TRUE" << std::endl;
	std::cout << "b : "<< b << std::endl;
	std::cout << "a : "<< a << std::endl;
	a--;
	if ((a != b) == true)
		std::cout << "a != b : TRUE" << std::endl;
	std::cout << "b : "<< b << std::endl;
	std::cout << "a : "<< a << std::endl;
	std::cout << a.max(a, b) << std::endl;
	std::cout << a.min(a, b) << std::endl;
}
