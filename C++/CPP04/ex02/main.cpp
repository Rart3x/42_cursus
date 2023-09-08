#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal* i = new Cat();
	//Animal* j = new Animal();
	//Animal test;

	i->makeSound();

	delete i;

	return (0);
}
