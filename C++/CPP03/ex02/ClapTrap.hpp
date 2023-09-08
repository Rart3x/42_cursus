#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap{

	public:
				ClapTrap(std::string name);
		ClapTrap(const ClapTrap &original);
		
		~ClapTrap();
		
		ClapTrap& operator=(const ClapTrap &original);
		void	attack(const std::string& target);
		void	beRepaired(unsigned int amount);
		void	takeDamage(unsigned int amount);
		unsigned int 	getAttackDamage();
		unsigned int		getEnergyPoints();
		unsigned int		getHitPoints();
		std::string getName();
		void	setHitPoints(unsigned int amount);
		void	setEnergyPoints(unsigned int amount);
		void	setAttackDamage(unsigned int amount);
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
};

#endif
