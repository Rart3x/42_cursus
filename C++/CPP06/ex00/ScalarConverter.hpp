#pragma once 

#include <cmath>
#include <cstring>
#include <iostream>

#include <stdlib.h>

class ScalarConverter {

    private:

    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);

        ~ScalarConverter();

        ScalarConverter& operator=(const ScalarConverter &src);

        void exceptions();
        void convert(char *str);

        void convertChar(char *str, double value);
        double convertDouble(char *str);
        void convertFloat(double value);
        void convertInt(double value);

        class CharException : public std::exception{
            public :
                virtual const char * what() const throw();
        };
        class CharExceptionUndisplayable : public std::exception{
            public :
                virtual const char * what() const throw();
        };
        class DoubleException : public std::exception{
            public :
                virtual const char * what() const throw();
        };
        class FloatException : public std::exception{
            public :
                virtual const char * what() const throw();
        };
        class FloatInfFException : public std::exception{
            public :
                virtual const char * what() const throw();
        };
        class FloatLessInfFException : public std::exception{
            public :
                virtual const char * what() const throw();
        };
        class FloatNanFException : public std::exception{
            public :
                virtual const char * what() const throw();
        };
        class IntException : public std::exception{
            public :
                virtual const char * what() const throw();
        };
        class InvalidNbArgs : public std::exception{
            public :
                virtual const char * what() const throw();
        };
};