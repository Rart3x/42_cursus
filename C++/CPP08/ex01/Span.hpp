#pragma once

#include <algorithm>
#include <iostream> 
#include <iterator>
#include <string>
#include <time.h>
#include <vector>

#define MAX_INT 2147483647

class Span{
    public:
        Span(unsigned int N);
        Span(const Span &src);

        Span& operator=(const Span &src);

        ~Span();

        void addNumber(unsigned int number);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void addNumberLoop(unsigned int number);

        void clearVec(void);

        unsigned int getMyStatic();
        unsigned int getMyMax();
        std::vector<unsigned int> getMyVec();

        class EmptyException : public std::exception{
            public :
                virtual const char * what() const throw();
        };

        class FilledException : public std::exception{
            public :
                virtual const char * what() const throw();
        };

        class InvalidNbValues : public std::exception{
            public :
                virtual const char * what() const throw();
        };

        

    private:
        Span();
        unsigned int myStatic;
        unsigned int max;
        std::vector<unsigned int> vec;


};