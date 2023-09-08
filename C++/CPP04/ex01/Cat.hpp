#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{

	public:
		Cat();
		Cat(Cat &src);

		virtual ~Cat();

		Cat& operator=(Cat &src);

		void	makeSound() const;

		std::string getType();
		Brain* getBrain();
		
	private:
		Brain* brain;

};

#endif
