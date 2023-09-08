#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA{
	
	private:
		Weapon&	hWeapon;
		std::string name;
	public:
		HumanA(std::string name, Weapon &hWeapon);
		~HumanA();
		void 	attack();
		void	setWeapon(Weapon &weapon);

};

#endif
