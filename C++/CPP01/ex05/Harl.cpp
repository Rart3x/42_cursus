#include "Harl.hpp"

Harl::Harl(){

}

Harl::~Harl(){

}

void    Harl::debug() {
    std::cout << "[DEBUG MESSAGE]" << std::endl;
}

void    Harl::error() {
    std::cout << "[ERROR MESSAGE]" << std::endl;
}

void    Harl::info() {
    std::cout << "[INFO MESSAGE]" << std::endl;
}

void    Harl::warning() {
    std::cout << "[WARNING MESSAGE]" << std::endl;
}

void	Harl::complain(std::string level){

	int			i;
	t_funct_ptr	tab[] = {&Harl::debug, &Harl::error, &Harl::info, &Harl::warning};
	std::string tab_level[] = {"DEBUG", "ERROR", "INFO", "WARNING"};

	for (i = 0; i < 4; i++){
		if (!tab_level[i].compare(level))
			break;
	}
	if (i < 4)
		(this->*tab[i])();
}
