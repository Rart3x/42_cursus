#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &original);

		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap &original);

		std::string getName();
		using ScavTrap::attack;
		void	whoAmI();
	
	private:
		std::string name;
};

#endif
