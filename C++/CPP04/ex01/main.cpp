#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{

	std::cout << "-----------mainPDF------------" << std::endl;
	
	const Animal* i = new Cat();
	const Animal* j = new Dog();


	delete i;
	delete j;

	std::cout << "-----------objectTab------------" << std::endl;
	
	Animal* tab[4];

	for (int i = 0; i < 2; i++){
		tab[i] = new Dog();
		tab[i]->makeSound();
	}
	for (int j = 2; j < 4; j++){
		tab[j] = new Cat();
		tab[j]->makeSound();	
	}

	Brain* tmp;
	tmp = tab[0]->getBrain();
	tmp->printIdeas(5);

	for (int i = 3; i >= 0; i--)
		delete tab[i];

	std::cout << "-----------pdfEx/deepCopy------------" << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
		Brain* stock;

		stock = basic.getBrain();
		stock->printIdeas(5);

		stock = tmp.getBrain();
		stock->printIdeas(5);
	}

	return 0;
}
