#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal{

	public:
		Animal();
		Animal(const Animal &src);

		Animal& operator=(const Animal &src);

		virtual ~Animal();

		virtual void makeSound() const;

		std::string getType() const;

		virtual Brain* getBrain();

	protected:
		std::string type;


};

#endif
