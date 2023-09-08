#include "sedCpy.hpp"

SedCpy::SedCpy(std::string filename){

	this->filename = filename;
}

SedCpy::~SedCpy(){

}

void SedCpy::replace_f(std::string filename, char *s1, char *s2){

	std::string 	line;
	std::string		sub;
	std::ifstream 	original(filename.c_str());
	filename += ".replace";	
	std::ofstream 	sedCopy(filename.c_str());

	if (original.is_open() && sedCopy.is_open())
	{
		unsigned int n = strlen(s1);
		while (std::getline(original, line))
		{
			unsigned int pos = 0;
			while (pos < line.length())
			{
				sub = line.substr(pos, pos + n);
				if (!strncmp(sub.c_str(), s1, n)){
					sedCopy << s2;
					pos += n;
				}
				else
				{
					sedCopy << line[pos];
					pos++;
				}
			}
			sedCopy << std::endl;
		}
		original.close();
		sedCopy.close();
	}
	else
		std::cout << "Unable to open file" << std::endl;
}

std::string SedCpy::getFilename(){

	return (this->filename);
}
