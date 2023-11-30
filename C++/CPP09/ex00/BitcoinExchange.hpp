#pragma once 

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

# define GREEN	"\033[32m"
# define RED	"\033[31m"
# define RESET	"\033[0m"

#define WHITESPACES " \t"

class Bitcoin
{
    public:
/*--------------------------Constructors------------------------*/
        Bitcoin();
        Bitcoin(const Bitcoin &src);
/*--------------------------Destructors-------------------------*/
        ~Bitcoin();
/*---------------------------Overloads--------------------------*/
        Bitcoin& operator=(const Bitcoin &src);
/*----------------------------Utils-----------------------------*/
        void    nbArgs(int ac);
        void    program(int ac, char **av);
        bool    verifFiles(std::string _filename);

        void    calculate(std::string _line, std::string _inputValue);

        void    extractDatas(std::string _filename, bool _isCSV);
        void    extractInputDatas(std::string _filename);

        std::map<int, std::string>      splitAt(std::string _line, int delim, bool flag);
        std::string                     split(std::string _line, int delim);
        std::string                     trim(std::string str);

        void    verifCSVDatas(std::map<int, std::string>);
        void    verifInputDatas(std::map<int, std::string>);

        bool    verifDateConformity(std::map<int, std::string> _map);
        bool    verifDateDigit(std::string str);

/*-----------------------------Setters--------------------------*/
        void    setFilename(std::string filename);
/*--------------------------Getters-----------------------------*/
        std::string getFilename(void) const;

        void    printError(std::string _errorMessage, std::string _arg);

    private:
        std::map<int, std::string> _csv;
        std::map<int, std::string> _input;
        
        std::string _badInput;
        std::string _filename;

        bool _endBool;
        bool _errorBool;
        bool _errorLoopInput;
};