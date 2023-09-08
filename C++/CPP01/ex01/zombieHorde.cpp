#include "Zombie.hpp"

Zombie	*Zombie::zombieHorde(int n, std::string name){

	Zombie	*zombieArray = new Zombie[n];

	for (int i = 0; i < n; i++)
	{	
		zombieArray[i].setName(name);
		zombieArray[i].announce();
	}
	return (zombieArray);
}
