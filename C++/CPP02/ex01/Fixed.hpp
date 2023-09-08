#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed{

	private:
		int					nb;
		static const int 	rawBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &original);
		Fixed(const int);
		Fixed(const float);
		
		Fixed& operator =(const Fixed &original);
		
		~Fixed();
		
		int		getRawBits(void)const;
		void 	setRawBits(int const raw);
		float 	toFloat(void)const;
		int		toInt(void)const;
};
		
std::ostream& operator <<(std::ostream &out, Fixed const &i);

#endif
