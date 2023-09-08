#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl{

	private:
		void	debug();
		void	error();
		void	info();
		void	warning();
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

typedef void (Harl::*t_funct_ptr)(void);

#endif
