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
	t_funct_ptr	tab[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string tab_level[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < 4; i++){
		if (!tab_level[i].compare(level))
			break;
	}
	
	while (i < 4){
		switch (i){
			case 0:
				(this->*tab[i])();
				break;
			case 1:
				(this->*tab[i])();
				break;
			case 2:
				(this->*tab[i])();
				break;
			case 3:
				(this->*tab[i])();
				break;
			}
		i++;
	}
}
