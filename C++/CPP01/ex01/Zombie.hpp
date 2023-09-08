#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	Zombie		*zombieHorde(int n, std::string name);
	void 		announce(void) const;
	void 		setName(std::string &name);
	std::string	getName();

private:
	std::string name;

};

#endif
