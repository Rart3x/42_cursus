#pragma once 

#include <cstring>
#include <iostream>
#include <stack>
#include <string>

#define MAX_INT 2147483647

#define SUM             operator1 + operator2
#define SUBSTRACTION    operator1 - operator2
#define FACTOR          operator1 * operator2
#define DIVISION        operator1 / operator2

class RPN{

    public:
        RPN();
        RPN(const RPN &src);

        ~RPN();

        RPN&    operator=(const RPN &src);

        bool    containsInvalidChar(const char* str)const;

        void    calculate(void);
        void    nbArgs(int ac)const;
        void    program(int ac, char **av);
        void    verifArguments(char **av);

        void    exceptions(void)const;

        class InvalidNbArgs : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        
        class InvalidChar : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class InvalidNbChar : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class MaxInt : public std::exception{
            public:
                virtual const char* what() const throw();
        };

    private:
        std::stack<char> stack;
};