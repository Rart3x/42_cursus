#include "Zombie.hpp"

int	main(void) {

	std::string name;

	std::cout << "--------Constructor-------" << std::endl;
	std::cout << "Please enter a Zombie name !" << std::endl;
	std::cin >> name;

	Zombie zomb(name);
	zomb.announce();

	std::cout << "--------ramdomChump()-------" << std::endl;
	std::string new_name;
	std::cout << "Please enter a new Zombie name !" << std::endl;
	std::cin >> new_name;

	randomChump(new_name);

	std::cout << "--------newZombie()-------" << std::endl;
	std::string last_name;
	std::cout << "Please enter a last Zombie name !" << std::endl;
	std::cin >> last_name;
	
	Zombie	*ptrZombie;
	ptrZombie = newZombie(last_name);
	ptrZombie->announce();
	delete ptrZombie;

	return (0);
}
