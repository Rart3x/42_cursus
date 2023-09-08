#include "Harl.hpp"

int	main(int argc, char **argv){

	(void)argv;
	if (argc != 1){
		std::cout << "Wrong number of argument" << std::endl;
		return (0);
	}

	Harl object;
	std::string in;
	
	do{
		std::cout << "Choose a level [DEBUG, INFO, WARNING, ERROR] or [EXIT] to quit" << std::endl;
		std::cin >> in;
		object.complain(in);
	}while (in.compare("EXIT"));

	return (0);
}
