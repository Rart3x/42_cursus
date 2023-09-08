#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	std::string	arg;
	
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		arg = argv[i];
		j = -1;
		while (arg[++j])
			std::cout << (char)toupper(arg[j]);
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
