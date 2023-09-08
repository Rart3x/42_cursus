#include "Harl.hpp"
#include <cstring>

int	main(int argc, char **argv){

	if (argc != 2){
		std::cout << "Wrong number of argument" << std::endl;
		return (0);
	}
	if (strcmp(argv[1], "DEBUG") && strcmp(argv[1], "INFO") && strcmp(argv[1], "WARNING") && strcmp(argv[1], "ERROR")){
		std::cout << "[Probably complaining about insignificant problems]" << std::endl;
		return (0);
	}

	Harl object;

	object.complain(argv[1]);
	return (0);
}
