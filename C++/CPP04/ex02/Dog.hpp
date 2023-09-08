#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{

	public:
		Dog();
		Dog(Dog &src);

		virtual ~Dog();

		Dog& operator=(Dog &src);
		
		void	makeSound() const;

		std::string getType();
		Brain* getBrain();
				
	private:
		Brain* brain;

};

#endif
