#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &src){

    if (this != &src)
        *this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src){

    if (this != &src)
        return (*this);
    return (*this);
}

ScalarConverter::~ScalarConverter(){}


void ScalarConverter::convert(char *str){

    double value;

    for (int i = 0; i < 4; i++)
    {
        try
        {
            switch (i)
            {
                case 0 :
                try{
                    value = convertDouble(str);
                }
                catch (...){
                    exceptions();
                }
                break;

                case 1 :
                try{
                    convertChar(str, value);
                }
                catch (...){
                    exceptions();
                }
                break;

                case 2 :
                try{
                    convertFloat(value);
                }
                catch (...){
                    exceptions();
                }
                break;

                case 3 :
                try{
                    convertInt(value);
                }
                catch (...){
                    exceptions();
                }
                break;
            }
        }
        catch (...)
        {
            exceptions();
        }
    }
}

void ScalarConverter::convertChar(char *str, double value){

	char c = static_cast<char>(value);

	if (c >= 32 && c <= 126){
        std::cout << "char: " << c << std::endl;
    }
    else if (!(c >= 32 && c <= 126))
		throw ScalarConverter::CharExceptionUndisplayable();
	else if (strlen(str) > 1)
		throw ScalarConverter::CharException();
}

double ScalarConverter::convertDouble(char *str){

    double tmp = 0.0;
 
    tmp = atof(str);

    if (!std::isinf(tmp) && !std::isnan(tmp) && (tmp > 2147483647 || tmp < -2147483648))
        throw ScalarConverter::DoubleException();
    std::cout << "double: " << tmp << ".0" << std::endl;
    return (tmp);
}

void ScalarConverter::convertFloat(double value){
	
    int f = static_cast<float>(value);

	if (std::isnan(value))
		throw ScalarConverter::FloatNanFException();
	if (std::isinf(value) && value > 0)
		throw ScalarConverter::FloatInfFException();
	else if (std::isinf(value) && value < 0)
		throw ScalarConverter::FloatLessInfFException();
    std::cout << "float: " << f << ".0f" << std::endl;
}

void ScalarConverter::convertInt(double value){

    int i = static_cast<int>(value);

    if (value < -2147483648 || value > 2147483647 || std::isinf(value) || std::isnan(value))
        throw ScalarConverter::IntException();
    std::cout << "int: " << i << std::endl;

}

void ScalarConverter::exceptions(){

    try{
        throw;
    }
    catch (ScalarConverter::CharException &e){
        std::cout << e.what() << std::endl;
    }
    catch (ScalarConverter::CharExceptionUndisplayable &e){
        std::cout << e.what() << std::endl;
    }
    catch (ScalarConverter::DoubleException &e){
        std::cout << e.what() << std::endl;
    }
    catch (ScalarConverter::FloatException &e){
        std::cout << e.what() << std::endl;
    }
    catch (ScalarConverter::IntException &e){
        std::cout << e.what() << std::endl;
    }
}

const char* ScalarConverter::CharException::what()const throw(){
    return ("char: impossible");
}

const char* ScalarConverter::CharExceptionUndisplayable::what()const throw(){
    return ("char: non displayable");
}

const char* ScalarConverter::DoubleException::what()const throw(){
    return ("double: impossible");
}

const char* ScalarConverter::FloatException::what()const throw(){
    return ("float: impossible");
}

const char* ScalarConverter::FloatInfFException::what()const throw(){
    return ("float: inf");
}

const char* ScalarConverter::FloatLessInfFException::what()const throw(){
    return ("float: -inf");
}

const char* ScalarConverter::FloatNanFException::what()const throw(){
    return ("float: nanf");
}

const char* ScalarConverter::IntException::what()const throw(){
    return ("int: impossible");
}

const char* ScalarConverter::InvalidNbArgs::what()const throw(){
    return ("error: invalid number of arguments");
}

