#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	j->makeSound();
	i->makeSound();
	meta->makeSound();
		
	delete i;
	delete j;
	delete meta;


	std::cout << std::endl;
	std::cout << "---------WrongAnimals----------" << std::endl;
	std::cout << std::endl;
	
	const WrongAnimal* meta1 = new WrongAnimal();
	const WrongAnimal* i1 = new WrongCat();
	
	i1->makeSound();
	meta1->makeSound();

	delete i1;
	delete meta1;

	return (0);
}
