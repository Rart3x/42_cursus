#ifndef SEDCPY_HPP
# define SEDCPY_HPP
# include <cstring>
# include <iostream>
# include <fstream>

class SedCpy{

	private:
		std::string filename;
	public:
		SedCpy(std::string filename);
		~SedCpy();
		void replace_f(std::string filename, char *s1, char *s2);
		std::string getFilename();
};

#endif
