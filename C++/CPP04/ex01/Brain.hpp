#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain{

	public:
		Brain();
		Brain(Brain &src);

		~Brain();

		Brain operator=(Brain &src);

		std::string* getIdeas();
		void printIdeas(int nbr);

	private:
		std::string ideas[100];

};

#endif
