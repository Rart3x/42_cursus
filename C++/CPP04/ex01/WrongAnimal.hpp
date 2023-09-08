#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal{

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);

		virtual ~WrongAnimal();
		void	makeSound() const;
		
		WrongAnimal& operator=(const WrongAnimal &src);

		std::string getType() const;
	
	protected:
		std::string type;

};

#endif
