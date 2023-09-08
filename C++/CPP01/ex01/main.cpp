#include "Zombie.hpp"

int	main(void) {

	std::string name;

	std::cout << "--------Constructor-------" << std::endl;
	std::cout << "Please enter a Zombie name !" << std::endl;
	std::cin >> name;

	Zombie zomb(name);
	zomb.announce();

	Zombie *ptrZombie;
	ptrZombie = zomb.zombieHorde(5, "tester");
	delete [] ptrZombie;
	return (0);
}
