#include "sedCpy.hpp"

int	main(int argc, char **argv){

	if (argc != 4){

		std::cout << "Program take 3 arguments !" << std::endl;
		return (0);
	}

	if (!strcmp(argv[1], "") || !strcmp(argv[2], "") || !strcmp(argv[3], ""))
	{
		std::cout << "Args cant be NULL" << std::endl;
		return (0);
	}
	
	std::string filename = argv[1];

	SedCpy sedCopy(filename);

	std::ifstream	original(filename.c_str());
	if (original.fail())
	{
		std::cout << "Can't open file" << std::endl;
	}
	else
	{
		std::string		line;

		std::cout << "---------ORIGINAL---------" << std::endl;
		while (std::getline(original, line))
			std::cout << line << std::endl;
		sedCopy.replace_f(filename, argv[2], argv[3]);

		
		filename += ".replace";
		std::ifstream	replaced(filename.c_str());

		std::cout << "---------REPLACED---------" << std::endl;
		while (std::getline(replaced, line))
			std::cout << line << std::endl;
	}
}
