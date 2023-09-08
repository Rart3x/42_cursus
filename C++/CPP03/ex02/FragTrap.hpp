#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap{

	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &original);

		FragTrap& operator=(const FragTrap &original);

		~FragTrap();
		void	highFivesGuys();

	private:
};

#endif
